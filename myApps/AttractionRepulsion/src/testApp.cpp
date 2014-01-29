#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    for(int i=0; i<1000; i++){
        Particle p;
        p.pos = ofVec2f(ofRandomWidth(), ofRandomHeight());
        p.vel = ofVec2f(ofRandom(-5,5), ofRandom(-5,5));
        ps.push_back(p);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i=0; i<1000; i++){
        ps[i].addAttractionForce(mouseX, mouseY, 1000, 0.5);
        ps[i].addRepulsionForce(mouseX, mouseY, 100, 5);
        ps[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i=0; i<1000; i++){
        ps[i].draw();
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
