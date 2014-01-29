#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    KochLine l(ofVec2f(0,500), ofVec2f(ofGetWidth(),500));
    lines.push_back(l);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    float coastline = 0;
    for(int i=0;i<lines.size();i++){
        lines[i].draw();
        coastline += lines[i].getLength();
    }
    cout<<coastline<<endl;
}

//--------------------------------------------------------------
void testApp::addGeneration(){
    vector<KochLine> ls;
    for(int i=0; i<lines.size(); i++){
        ofVec2f a = lines[i].a();
        ofVec2f b = lines[i].b();
        ofVec2f c = lines[i].c();
        ofVec2f d = lines[i].d();
        ofVec2f e = lines[i].e();
        ls.push_back(KochLine(a,b));
        ls.push_back(KochLine(b,c));
        ls.push_back(KochLine(c,d));
        ls.push_back(KochLine(d,e));
    }
    
    lines = ls;
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
    addGeneration();
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
