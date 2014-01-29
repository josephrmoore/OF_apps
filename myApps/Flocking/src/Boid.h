//
//  Boid.h
//  Flocking
//
//  Created by Joseph Moore on 10/22/13.
//
//

#pragma once

#include "ofMain.h"

class Boid {
public:
    Boid();
    void update();
    void draw();

    void applyForce(ofVec3f frc);
    void pullToCenter(ofVec3f center);
    
    float damping;
    ofVec3f pos, vel, acc;
    float minSpeed, maxSpeed, maxDistance;
};