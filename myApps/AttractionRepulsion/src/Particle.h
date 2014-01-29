//
//  Particle.h
//  AttractionRepulsion
//
//  Created by Joseph Moore on 10/1/13.
//
//

#pragma once

#include "ofMain.h"

class Particle{
public:
    Particle();
    ofVec2f pos, vel, acc;
    void addForce(ofVec2f force);
    void update();
    void draw();
    
    void addRepulsionForce(float px, float py, float radius, float strength);
    void addAttractionForce(float px, float py, float radius, float strength);
    
    float damping;
};