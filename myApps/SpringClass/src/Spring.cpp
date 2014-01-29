//
//  Spring.cpp
//  SpringClass
//
//  Created by Joseph Moore on 11/12/13.
//
//

#include "Spring.h"

Spring::Spring(){
    k = 0.1;
}

//--------------------------------------------------------------
void Spring::update(){
    ofVec2f force = s1->pos - s2->pos;
    float len = force.length();
    float stretchLen = len - restLen;
    force.normalize();
    force *= -1*k*stretchLen;
    
    s1->applyForce(force);
    s2->applyForce(-force);
    
//    s1->update();
//    s2->update();
    
//    applyForce(ofVec2f(0,gravity));
    
}


//--------------------------------------------------------------
void Spring::draw(){
    ofLine(s1->pos,s2->pos);
}

//--------------------------------------------------------------
void Spring::set(SpringJoint *_s1, SpringJoint *_s2, float _k, float _restLen){
    s1 = _s1;
    s2 = _s2;
    k = _k;
    restLen = _restLen;
}