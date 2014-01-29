//
//  Spring.h
//  SpringClass
//
//  Created by Joseph Moore on 11/12/13.
//
//

#pragma once

#include "ofMain.h"
#include "SpringJoint.h"

class Spring {
    
public:
    Spring();
    void set(SpringJoint *_s1, SpringJoint *_s2, float k, float _restLen);
    void update();
    void draw();
    SpringJoint *s1, *s2;
    float k, restLen;
};
