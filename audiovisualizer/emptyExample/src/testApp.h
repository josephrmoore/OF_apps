#pragma once

#include "ofMain.h"
#include "demoParticle.h"
#include "fft.h"
#include "FFTOctaveAnalyzer.h"

#define BUFFER_SIZE 512

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void resetParticles();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		particleMode currentMode;
		string currentModeStr; 

		vector <demoParticle> p;
        vector <demoParticle> p2;
        vector <demoParticle> p3;
        vector <demoParticle> p4;
		vector <ofPoint> attractPoints;
		vector <ofPoint> attractPointsWithMovement;
    
        void audioIn 	(float * input, int bufferSize, int nChannels); 
        
        FFTOctaveAnalyzer FFTanalyzer;
        
        float left[BUFFER_SIZE];
        float right[BUFFER_SIZE];
        
        fft		myfft;
        
        float magnitude[BUFFER_SIZE];
        float phase[BUFFER_SIZE];
        float power[BUFFER_SIZE];
        float freq[BUFFER_SIZE/2];
        int current, high, low, mid, scale_h, scale_m, scale_l;
        int high_r, high_g, high_b;
        int mid_r, mid_g, mid_b;
        int low_r, low_g, low_b;
};