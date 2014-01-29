//
//  Boid.cpp
//  Flocking
//
//  Created by Joseph Moore on 10/22/13.
//
//

#include "Boid.h"

Boid::Boid(){
    damping = ofRandom(0.9, 0.95);
    minSpeed = ofRandom(0.5, 1.5);
//    maxSpeed = ofRandom(3.0, 100.0);
    maxDistance = 100.0;
}

void Boid::applyForce(ofVec3f frc){
    acc += frc;
}

void Boid::update(){
    vel += acc;
    vel.limit(3.0);
    if(vel.lengthSquared()<(minSpeed*minSpeed)){
        vel.normalized()*minSpeed;
    }
    pos += vel;
    vel *= damping;
    acc.set(0);
}

void Boid::draw(){
//    ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
    ofSetColor(255);
    ofCircle(pos, 2);
    ofSetColor(255,0,0); // this is red.
    ofLine(pos, pos-vel*5.0);
    
}

void Boid::pullToCenter(ofVec3f center){
    ofVec3f dir = pos-center;
    float dist = dir.length();
    if(dist>maxDistance){
        dir.normalize();
        vel -= dir*(dist-maxDistance)*0.0001f;
    }
}