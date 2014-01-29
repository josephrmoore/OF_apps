#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    sender.setup("localhost", 12345);
    pos = ofGetWindowSize()/2;
    vel = ofVec2f(10,0);
}

//--------------------------------------------------------------
void testApp::update(){
    pos += vel;
    if(pos.x<0 || pos.x>ofGetWidth()*2){
        vel *= -1;
    }
    if(pos.y<0 || pos.y>ofGetHeight()){
        vel *= -1;        
    }
    ofxOscMessage m;
    m.setAddress("/mouse/ball");
    m.addFloatArg(pos.x);
    m.addFloatArg(pos.y);
    sender.sendMessage(m);
}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushMatrix();
    ofTranslate(-ofGetWidth(),0);
    ofSetColor(150);
    ofCircle(pos, 20);
    ofSetColor(255,0,0);
    ofCircle(mouse_pos, 10);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    mouse_pos.set(x,y);
    ofxOscMessage m;
    m.setAddress("/mouse/pos");
    m.addIntArg(mouse_pos.x);
    m.addIntArg(mouse_pos.y);
    sender.sendMessage(m);
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
