//
//  Particle.cpp
//  GridParticles
//
//  Created by Joseph Moore on 9/24/13.
//
//

#include "Particle.h"

Particle::Particle(ofVec2f pos){
    this->pos = pos;
    radius = 4;
    grayValue = 255;
//    radius = cos(pos.x*.1) + sin(pos.y*.1) + 2;
//    radius = (sin(pos.x*pos.y)+1.0) * 2;
}

void Particle::draw(){
    ofSetColor(grayValue);
    ofCircle(pos, radius);
}

void Particle::update(const ofImage &img){
    grayValue = img.getColor(pos.x, pos.y).r;
    radius = ((float)grayValue/255.0)*7.0;
}