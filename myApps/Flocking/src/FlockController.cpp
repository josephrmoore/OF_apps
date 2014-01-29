//
//  FlockController.cpp
//  Flocking
//
//  Created by Joseph Moore on 10/22/13.
//
//

#include "FlockController.h"

FlockController::FlockController(){
    attractStrength = 0.01;
    alignStrength = 0.01;
    separateStrength = 0.01;
}


void FlockController::addBoids(int num){
    for(int i=0; i<num; i++){
        float phi = ofRandom( 0, TWO_PI );
		float costheta = ofRandom( -1.0f, 1.0f );
		
		float rho = sqrt( 1.0f - costheta * costheta );
		float x = rho * cos( phi );
		float y = rho * sin( phi );
		float z = costheta;
		
        ofVec3f randVec(x, y, z);
        
		ofVec3f pos = randVec * ofRandom( 100.0f, 600.0f );
		ofVec3f vel = -randVec;
        
        Boid b;
        b.pos = pos;
        b.vel = vel;
        boids.push_back(b);
    }
}

void FlockController::applyForces(float zoneRadius, float separateThresh, float alignThresh, float sepSt, float alSt, float attSt){
    
    float zoneRadiusSquared = zoneRadius*zoneRadius;
    for(vector<Boid>::iterator b1=boids.begin(); b1 != boids.end(); ++b1){
        vector<Boid>::iterator b2 = b1+1;
        for(b2; b2 != boids.end(); ++b2){
            ofVec3f dir = b1->pos - b2->pos;
            float lenSq = dir.lengthSquared();
            if(lenSq<zoneRadiusSquared){
                float pct = lenSq/zoneRadiusSquared;
                if(pct==0){
                    pct = 0.00000001;
                }
                if(pct<separateThresh){
                    // separate
                    float adj_pct = 1.0 - ofMap(pct, 0.0, separateThresh, 0.0, 1.0);
                    ofVec3f F = dir.normalized() * adj_pct * sepSt;
                    b1->applyForce(F);
                    b2->applyForce(-F);
                } else if(pct<alignThresh){
//                  // align
                    float adj_pct = 1.0 - ofMap(pct, separateThresh, alignThresh, 0.0, 1.0);
                    float F = adj_pct*alSt;
                    b1->applyForce(b2->vel.normalized()*F);
                    b2->applyForce(b1->vel.normalized()*F);
                } else {
                    // attract
                    float adj_pct = ofMap(pct, alignThresh, 1.0, 0.0, 1.0);
                    ofVec3f F = dir.normalized() * adj_pct * attSt;
                    b1->applyForce(-F);
                    b2->applyForce(F);
                }
            }
        }
    }
    
}


void FlockController::update(){
    for(int i=0; i<boids.size(); i++){
        boids[i].pullToCenter(ofVec3f(0,0,0));
        boids[i].update();
    }
}

void FlockController::draw(){
    for(int i=0; i<boids.size(); i++){
        boids[i].draw();
    }
}