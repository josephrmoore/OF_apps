#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    totalZeros = 0;
    totalVolume = 0;
    finalVolume = 0;
    
    positive = false;
    prevPositive = false;
    
    soundStream.setup(this, 0, 1, 44100, 1024, 4);
    bk.r = 255;
    bk.g = 0;
    bk.b = 0;
    prevVol = 0;
    prevFreq = 0;
    freq = 0;
}

//--------------------------------------------------------------
void testApp::update(){

    hue = ofMap(freq, 0, 4000, 0, 360);
    brightness = ofMap(finalVolume, 0, 1, 0, 255);
    hue = (.1*hue)+(.9*bk.getHue());
    brightness = (.1*brightness)+(.9*bk.getBrightness());
    bk.r = 255;
    bk.g = 0;
    bk.b = 0;
    bk.setHue(hue);
    bk.setBrightness(brightness);
}

//--------------------------------------------------------------
void testApp::draw(){    
    ofBackground(bk.r, bk.g, bk.b);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::audioIn(float * input, int bufferSize, int nChannels){
    totalVolume = 0;
    totalZeros = 0;
    
    // adding the sum of all the squares
    
    for (int i = 0; i < bufferSize; i++){
        totalVolume += input[i]*input[i]; 
    }
    
    finalVolume = sqrt(totalVolume/bufferSize);
    
    
    
    
    for (int i = 0; i < bufferSize-1; i++){
        if(input[i] < 0){
            if(input[i+1]>0){
                totalZeros++;
            }
        } else {
            if(input[i+1]<0){
                totalZeros++;
            }
        }
        
    }
    
    freq = (totalZeros/2) / (bufferSize / (float)44100);

    
}

