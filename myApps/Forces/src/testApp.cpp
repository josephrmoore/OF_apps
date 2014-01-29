#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){
    ofVec2f gravity(0.0, 0.1);
    ofVec2f wind(0.1, 0.0);
	for (int i=0; i < particles.size(); i++){
        particles[i].applyForce(gravity);
        particles[i].applyForce(wind);
        particles[i].applyForce(particles[i].damping);
//        particles[i].vel *= 0.01; // cool mistake
        particles[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for (int i=0; i < particles.size(); i++){
        particles[i].draw();
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
    Particle myParticle;
    myParticle.mass = ofRandom(0.2, 3.0);
    myParticle.setParams(x, y, s(10.0, 200.0, false),c(10.0, 200.0, false));
    particles.push_back(myParticle);
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

float testApp::s(float mult, float period, bool norm){
    float f;
    if(norm){
        f = mult * ofMap(sin(ofGetElapsedTimeMillis()/period), -1.0, 1.0, 0.0, 1.0);
    } else {
        f = mult * sin(ofGetElapsedTimeMillis()/period);
    }
    return f;
}

float testApp::c(float mult, float period, bool norm){
    float f;
    if(norm){
        f = mult * ofMap(sin(ofGetElapsedTimeMillis()/period), -1.0, 1.0, 0.0, 1.0);
    } else {
        f = mult * cos(ofGetElapsedTimeMillis()/period);
    }
    return f;
}
