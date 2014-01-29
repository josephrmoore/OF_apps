#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    int tmp = 5;
//    int tmp2 = 10;
    int *myPtr = &tmp;
    
    int val = (*myPtr);
    tmp = 8;
    
    myPtr = &val;
    
//    int *newPtr = new int;
    
    cout<<"myPtr: "<<myPtr<<" "<<(*myPtr)<<endl;
    cout<<"temp: "<<&tmp<<" "<<tmp<<endl;
    cout<<"val: "<<&val<<" "<<val<<endl;
}

//--------------------------------------------------------------
void testApp::testFunction(int &input){
    int internalPtr = input;
    input = 10;
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){

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
