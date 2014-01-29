//
//  KochLine.cpp
//  Koch
//
//  Created by Joseph Moore on 11/19/13.
//
//

#include "KochLine.h"

KochLine::KochLine(ofVec2f _start, ofVec2f _end){
    start = _start;
    end = _end;
}

void KochLine::draw(){
    ofLine(start, end);
}


float KochLine::getLength(){
    return start.distance(end);
}

ofVec2f KochLine::a(){
    return start;
}
ofVec2f KochLine::b(){
    return ((end-start)*0.333334)+start;
}
ofVec2f KochLine::c(){
    ofVec2f line = ((end-start)*0.333334);
    line.rotate(-60);
    return b()+line;
}
ofVec2f KochLine::d(){
    return ((end-start)*0.666667)+start;
}
ofVec2f KochLine::e(){
    return end;
}
