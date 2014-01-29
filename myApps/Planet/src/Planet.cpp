//
//  Planet.cpp
//  Planet
//
//  Created by Joseph Moore on 10/1/13.
//
//

#include "Planet.h"

Planet::Planet(){
    mass = 1.0;
}

void Planet::applyForce(ofVec2f force){
    acc += (force/mass);
}


void Planet::update(){
    vel += acc;
    pos += vel;
    
    acc.set(0);
}

ofVec2f Planet::attract(Planet p){
    ofVec2f forceDir = pos - p.pos;
    float dist = forceDir.length();
//    cout<<dist<<endl;
    if(dist == 0){
        return ofVec2f(0,0);
    } else {
        return forceDir*G*mass*p.mass/(dist*dist);        
    }
}

void Planet::draw(){
    ofCircle(pos, mass*10);
}