#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    gui = new ofxUICanvas();
    gui->addLabel("My Controls");
    gui->addSpacer();
    gui->addButton("mybutton", false, 40, 40);
    gui->addSlider("radius", 0, 100, 50);
    ofAddListener(gui->newGUIEvent, this, &testApp::onGuiEvent); // what we're listening for,
                                                                 // who's listening for it,
                                                                 // and the function to run when it happens
    radius = 50.0;
    color = ofColor(255,0,255);
    gui->loadSettings("test_settings.xml");
}

//--------------------------------------------------------------
void testApp::exit(){
    gui->saveSettings("test_settings.xml");
    delete gui;
}

//--------------------------------------------------------------
void testApp::onGuiEvent(ofxUIEventArgs &e){
    if(e.getName() == "radius"){
        ofxUISlider *radiusSlider = (ofxUISlider*)e.widget;
        radius = radiusSlider->getScaledValue();
    } if(e.getName() == "mybutton"){
        ofxUIButton *colorToggle = (ofxUIButton*)e.widget;
        if(colorToggle->getValue() == 0){
            color = ofColor(255,0,255);
        } else {
            color = ofColor(0,0,255);
        }
    }
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(color);
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, radius);
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
