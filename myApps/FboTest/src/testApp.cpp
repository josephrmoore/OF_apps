#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    pos.set(ofGetWidth()/2, ofGetHeight()/2);
    vel.set(10,5);
    f.allocate(ofGetWidth(), ofGetHeight());
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
    pos += vel;
    if(pos.x<0||pos.x>ofGetWidth()){
        vel.x *= -1.0;
    }
    if(pos.y<0||pos.y>ofGetHeight()){
        vel.y *= -1.0;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
//    cam.begin();
    f.begin();
    ofClear(255,255,255,0);
    ofPushMatrix();
    ofTranslate(pos);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofRect(-50,-50,50,50);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofPopMatrix();
    f.end();
    f.draw(0,0);
    f.draw(200,0);
    f.draw(0,200);
    f.draw(200,200);

    //    cam.end();
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
