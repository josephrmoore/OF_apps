#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    box2d.init();
    box2d.setGravity(0, 2);
    box2d.createBounds(-ofGetWidth(),0, ofGetWidth()*3, ofGetHeight());
    box2d.setFPS(30.0);
    box2d.registerGrabbing();
    potato.setPhysics(3.0, 0.53, 0.1);
    potato.setup(box2d.getWorld(), 100,100,10,10);
    receiver.setup(12345);
}

//--------------------------------------------------------------
void testApp::update(){
    checkOsc();
    potato.setPosition(pos);
    potato.setVelocity(vel);
    potato.setFixedRotation(rot);
    box2d.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushMatrix();
    if (pos.x>ofGetWidth()*2){
        ofTranslate(ofGetScreenWidth(),0);
    }
    ofPopMatrix();
}

void testApp::checkOsc(){
    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        string addr = m.getAddress();
        if(addr == "/potato"){
            float x = m.getArgAsInt32(0);
            float y = m.getArgAsInt32(1);
            pos.set(x,y);
            float vx = m.getArgAsInt32(0);
            float vy = m.getArgAsInt32(1);
            vel.set(vx,vy);
            rot = m.getArgAsInt32(0);
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
