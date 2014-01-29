//
//  Particle.cpp
//  ParticleControl
//
//  Created by Joseph Moore on 9/28/13.
//
//

#include "Particle.h"

Particle::Particle() {
    setParams(0,0,0,0);
    damping = ofVec2f( -0.1f );
    color = ofColor(ofRandom(0,180), ofRandom(100, 255));
    mass = 1.0;
}

Particle::Particle(ofVec2f p) {
    setParams(p.x,p.y,0,0);
    damping = ofVec2f( -0.1f );
    color = ofColor(ofRandom(0,180), ofRandom(100, 255));
    mass = 1.0;
}

void Particle::setParams( float px, float py, float vx, float vy ){
    pos.set( px, py );
    vel.set( vx, vy );
}

void Particle::applyForce( ofVec2f force ){
    acc += force/mass;
}

void Particle::resetForces() {
    frc.set(0,0);
}

void Particle::update() {
    vel = vel + acc;
    pos = pos + vel;
    
    if(pos.x<0||pos.x>ofGetWidth()){
        vel.x *=-1;
    }
    if(pos.x<0){
        vel.x *=-1;
    }
    if(pos.y<0||pos.y>ofGetHeight()){
        vel.y *=-1;
    }
        
    acc.set(0);
}

void Particle::draw() {
    ofSetColor(color);
    ofCircle(pos, mass*10);
}