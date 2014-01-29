#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60.0);
    earth.pos = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
    earth.mass = 2.0;
    moon.mass = 0.5;
    moon.pos = ofVec2f(ofGetWidth()/2+100, ofGetHeight()/2+100);
    moon.vel = ofVec2f(0,-1);
}

//--------------------------------------------------------------
void testApp::update(){
    ofVec2f pull = earth.attract(moon);
//    cout<<pull<<endl;
    moon.applyForce(pull);
    moon.update();
    earth.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    earth.draw();
    moon.draw();
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
