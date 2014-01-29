//
//  SpringJoint.cpp
//  SpringClass
//
//  Created by Joseph Moore on 11/12/13.
//
//

#include "SpringJoint.h"

//--------------------------------------------------------------
void SpringJoint::applyForce(ofVec2f force){
    acc += force;
}

//--------------------------------------------------------------
void SpringJoint::update(){
    vel += acc;
    vel *= 0.95;
    pos += vel;
    acc.set(0);
    
    if(pos.x<0||pos.x>ofGetWidth()){
        vel.x *= -1.0;
    }
    
    if(pos.y<0||pos.y>ofGetHeight()){
        vel.y *= -1.0;
    }
}

//--------------------------------------------------------------
void SpringJoint::draw(){
    ofCircle(pos,5);
}