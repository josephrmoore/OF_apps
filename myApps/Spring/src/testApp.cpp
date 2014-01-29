#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    k = 0.05;
    restLength = 200.0;
    anchor = ofVec2f(ofGetWidth()/2,ofGetHeight()/2-205);
    handle = ofVec2f(ofGetWidth()/2,ofGetHeight()/2);
    gravity = 1.5;
}

//--------------------------------------------------------------
void testApp::update(){
    
    if(draggable){
        return;
    }
    
    ofVec2f force = handle - anchor;
    float len = force.length();
    float stretchLen = len - restLength;
    force.normalize();
    force *= -1*k*stretchLen;
    applyForce(force);
    applyForce(ofVec2f(0,gravity));
    vel += acc;
    vel *= 0.95;
    handle += vel;
    acc.set(0);
}

//--------------------------------------------------------------
void testApp::draw(){
    ofLine(anchor,handle);
    ofCircle(anchor,10);
    ofCircle(handle,20);
}

//--------------------------------------------------------------
void testApp::applyForce(ofVec2f force){
    acc += force;
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
    if(draggable){
        handle.set(x,y);
    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    if(ofVec2f(x,y).distance(handle)<30){
        draggable = true;
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    draggable = false;
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
