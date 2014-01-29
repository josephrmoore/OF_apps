#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define PORT 9000


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void audioIn(float * input, int bufferSize, int nChannels);

    ofSoundStream soundStream;
    
    float totalVolume, totalZeros, finalVolume, freq;
    
    bool positive, prevPositive, trigger, sq;
    int brightness, hue;
    
    float prevVol, prevFreq, grain;
    
    int squares, triggered;
    
    int r, sw, sh, offset;
        
    ofColor bk;
    
    int w, h;
	float roll, yaw, pitch, accel, wiiX, wiiY;
	ofxOscReceiver receiver;

};
