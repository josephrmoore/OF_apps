#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    img.loadImage("america.jpg");
    int xRes = img.getWidth()/10;
    int yRes = img.getHeight()/10;
    for(int y=0; y<yRes; y++){
        for(int x=0; x<xRes; x++){
            addParticle(x,y);
        }
    }
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i=0; i<particles.size(); i++){
        particles[i].update(img);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i=0; i<particles.size(); i++){
        particles[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::addParticle(float x, float y){
    float xPos = (x+0.5) * 10.0;
    float yPos = (y+0.5) * 10.0;
    particles.push_back(Particle(ofVec2f(xPos, yPos)));
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
