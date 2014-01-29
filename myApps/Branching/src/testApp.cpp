#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    generation = 0;
    theta = 45;
    length = 200;
}

//--------------------------------------------------------------
void testApp::update(){
    
}

void testApp::branch(float length){
    generation++;
    ofPushMatrix();
        ofLine(0,0,0,-length);
        ofTranslate(0,-length);
    
        float noise = ofNoise(generation, ofGetElapsedTimef()*0.1);
    
        if(length>2){
            ofPushMatrix();
                ofRotate(theta+noise*10.0);
                branch(length*0.66667);
            ofPopMatrix();
            ofPushMatrix();
                ofRotate(-theta+noise*10.0);
                branch(length*0.66667);
            ofPopMatrix();
        }
    
    ofPopMatrix();
    generation--;
}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight());
        branch(length);
    ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    theta = ofMap(x,0,ofGetWidth(),-180,180);
    length = ofMap(y,0,ofGetHeight(),10,400);
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
