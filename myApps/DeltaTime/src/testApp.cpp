#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    for(int i=0; i<50; i++){
        Particle p;
        p.pos = ofVec2f(ofRandomWidth(), ofRandomHeight());
        p.vel = ofVec2f(10, 0);
        ps.push_back(p);
    }
    
    lastTime = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void testApp::update(){
    float dt = ofGetElapsedTimef()-lastTime;
    lastTime = ofGetElapsedTimef();
    cout<<dt<<endl;
    for(int i=0; i<ps.size(); i++){
        ps[i].update(dt*40*timeScale);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i=0; i<ps.size(); i++){
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
    timeScale = ofMap(x, 0, ofGetWidth(), -3, 3);
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
