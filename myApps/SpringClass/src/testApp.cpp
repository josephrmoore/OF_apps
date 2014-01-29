#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    for(int i=0;i<4; i++){
        SpringJoint sj;
        sj.pos = ofVec2f(ofGetWidth()/2,10+i*195);
        jointList.push_back(sj);
    }
    
    for(int i=0;i<jointList.size()-1; i++){
        Spring s;
        s.set(&jointList[i], &jointList[i+1], 0.05, 200);
        springList.push_back(s);
    }
    Spring s;
    s.set(&jointList[jointList.size()-1], &jointList[0], 0.05, 200);
    springList.push_back(s);
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i=0; i<jointList.size(); i++){
        jointList[i].update();
    }
    for(int i=0; i<springList.size(); i++){
        springList[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i=0; i<jointList.size(); i++){
        jointList[i].draw();
    }
    for(int i=0; i<springList.size(); i++){
        springList[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    int rand = floor(ofRandom(jointList.size()));
    jointList[rand].applyForce(ofVec2f(ofRandom(-10,10)));
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
