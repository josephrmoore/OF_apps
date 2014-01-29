//
//  Planet.h
//  Planet
//
//  Created by Joseph Moore on 10/1/13.
//
//

#pragma once
#include "ofMain.h"

class Planet {
public:
    Planet();
    
    void applyForce(ofVec2f force);
    void update();
    void draw();
    
    ofVec2f attract (Planet p);
    
    ofVec2f pos, vel, acc;
    float mass;
    
    const static float G = 0.4;
};