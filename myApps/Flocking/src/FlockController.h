//
//  FlockController.h
//  Flocking
//
//  Created by Joseph Moore on 10/22/13.
//
//

#pragma once
#include "ofMain.h"
#include "Boid.h"

class FlockController {
public:
    FlockController();
    
    void applyForces(float zoneRadius, float separateThresh=0.4, float alignThresh=0.7, float sepSt=0.01, float alSt=0.005, float attSt=0.01);
    
    void addBoids(int num=1);
    void update();
    void draw();
    vector<Boid> boids;
    float attractStrength, separateStrength, alignStrength;
};