//
//  Particle.h
//  GridParticles
//
//  Created by Joseph Moore on 9/24/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle(ofVec2f pos);
    
    ofVec2f pos;
    float radius, grayValue;
    void draw();
    void update(const ofImage &img);
};