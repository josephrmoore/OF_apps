#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxBox2d.h"


class testApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    ofxOscSender sender, sender2;
    ofxBox2d box2d;
    ofxBox2dRect potato;
    ofVec2f pos, vel;
    float rot, angle, angularVel;
};
