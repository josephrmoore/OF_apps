#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    box2d.init();
    box2d.setGravity(0, 2);
    box2d.createBounds(-ofGetWidth(),0, ofGetWidth()*3, ofGetHeight());
    box2d.setFPS(30.0);
    box2d.registerGrabbing();
    potato.setPhysics(3.0, 0.53, 0.1);
    potato.setup(box2d.getWorld(), 100,100,100,100);
    sender.setup("169.254.192.88", 12345);
    sender2.setup("169.254.154.116", 12345);

}

//--------------------------------------------------------------
void testApp::update(){
    box2d.update();
    pos = potato.getPosition();
    vel = potato.getVelocity();
    rot = potato.getRotation();
    ofxOscMessage m;
    m.setAddress("/potato");
    m.addIntArg(pos.x);
    m.addIntArg(pos.y);
    m.addIntArg(vel.x);
    m.addIntArg(vel.y);
    m.addIntArg(rot);
    sender.sendMessage(m);
    sender2.sendMessage(m);
}

//--------------------------------------------------------------
void testApp::draw(){
    potato.draw();
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
