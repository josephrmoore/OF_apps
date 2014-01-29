//
//  Particle.cpp
//  SingleParticle
//
//  Created by Joseph Moore on 9/24/13.
//
//

#include "Particle.h"

Particle::Particle(){
    pos.set(0,0);
    vel.set(0,0);
    damping.set(0,0);
    setParams(pos, vel);
}

void Particle::setParams(ofVec2f pos, ofVec2f vel){
    this->pos = pos;
    this->vel = vel;
}

void Particle::addForce(ofVec2f force){
    this->force += force;
}

void Particle::resetForces(){
    force.set(0,0);
}

void Particle::addDampingForce(){
    this->force = this->force - (this->vel * this->damping);
}

void Particle::update(){
    this->vel += this->force;
    this->pos += this->vel;
}

void Particle::draw(){
    ofCircle(this->pos, 3);
}