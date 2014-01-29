#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    particle.pos.set(300,300);
    particle.vel.set(ofRandom(-10,10), ofRandom(-10,10));
    particle.setParams(particle.pos, particle.vel);
    for(int i=0; i<1000; i++){
        addParticle();
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i=0; i<particles.size(); i++){
        particles[i].resetForces();
        particles[i].addForce(ofVec2f(0,0.1));
        particles[i].addDampingForce();
        particles[i].update();
    }
}
//--------------------------------------------------------------
void testApp::addParticle(){
    Particle p;
    p.setParams(ofPoint(300,300), ofPoint(ofRandom(-4,4), ofRandom(-4,4)));
    particles.push_back(p);
}


//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    particle.draw();
    for(int i=0; i<particles.size(); i++){
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

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    particle.setParams(ofPoint(x,y), ofPoint(ofRandom(-10,10), ofRandom(-10,10)));
    float circleValue = ofRandom(TWO_PI);
    for(int i=0; i<particles.size(); i++){
        ofVec2f v = ofPoint(cos(circleValue)*ofRandom(0,4), sin(circleValue)*ofRandom(0,4));
        particles[i].setParams(ofPoint(x,y), v);

    }
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
