//
//  Particle.h
//  SingleParticle
//
//  Created by Joseph Moore on 9/24/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
    public:
        Particle();
        void update();
        void draw();
    
        void setParams(ofVec2f pos, ofVec2f vel);
        void addForce(ofVec2f force);
        void addDampingForce();
        void resetForces();
    
        ofVec2f pos, vel, force, damping;
    
};