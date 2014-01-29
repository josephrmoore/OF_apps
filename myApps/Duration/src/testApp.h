#pragma once

#include "ofMain.h"
#include "fft.h"
#include "FFTOctaveAnalyzer.h"
#include "aubioAnalyzer.h"
#include "ofxOsc.h"
#include "ofxNetwork.h"

#define BUFFER_SIZE 512

#define HOST "localhost"
#define PORT 12345

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
    void audioAnalisys();
    void SentMessages();
    
    void audioReceived 	(float * input, int bufferSize, int nChannels);
    aubioAnalyzer Channel01_Aubio;

    FFTOctaveAnalyzer Channel01_Analyzer;
    
    float Channel01[BUFFER_SIZE];
    
    fft		Channel01_fft;
        
    float avg_power;
    float peakTime, decayRate, HiGain, LowGain;
    
    float Channel01_magnitude[BUFFER_SIZE];
    float Channel01_phase[BUFFER_SIZE];
    float Channel01_power[BUFFER_SIZE];
    float Channel01_freq[BUFFER_SIZE/2];
    
    vector <float> Channel01_holdFreq;
    vector <float> Channel01_deltaFreq;
    
    float Channel01_att;
    
    ofSoundStream AudioIn;
    
    float Channel01_peakPitch;
    float Channel01_UsefulPitch;
    ofColor pitched;
    
    ofxOscSender Sender;
    
    int Channel01_FFT_size;
    
    float Channel01_Pitch;
    float Channel01_Attack;
    float Channel01_Amplitude;
    float Channel01_LinearPitch;
    
    ofxUDPManager udpConnection2;
    ofxUDPManager udpConnection;
    
    
    //first violin values
    float x,y,z,magx,magy,magz;
    
    //second violin values
    float x2,y2,z2,magx2,magy2,magz2;
    
};
