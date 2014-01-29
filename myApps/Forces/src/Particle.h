//
//  Particle.h
//  ParticleControl
//
//  Created by Joseph Moore on 9/28/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle();
    Particle(ofVec2f pos);
    void update();
    void draw();
    
    void setParams( float px, float py, float vx, float vy );
    void applyForce( ofVec2f force );
    void resetForces();
    
    ofVec2f pos, vel, acc, frc, damping;
    ofColor color;
    
    float mass;
};