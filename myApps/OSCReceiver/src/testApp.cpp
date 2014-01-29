#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    receiver.setup(12345);
    ofBackground(255);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void testApp::update(){
    checkOsc();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0);
    ofEllipse(ofGetWidth()/2,ofGetHeight()/2, mouse_pos.x/2, mouse_pos.y/2);
    ofSetColor(150);
    ofCircle(pos,20);
}
//--------------------------------------------------------------
void testApp::checkOsc(){
    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        string addr = m.getAddress();
        if(addr == "/mouse/pos"){
            float x = m.getArgAsInt32(0);
            float y = m.getArgAsInt32(1);
            mouse_pos.set(x,y);
        }
        string ball = m.getAddress();
        if(ball == "/mouse/ball"){
            float x = m.getArgAsFloat(0);
            float y = m.getArgAsFloat(1);
            pos.set(x,y);
        }
    }
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
