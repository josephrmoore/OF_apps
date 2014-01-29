#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    Sender.setup(HOST, PORT);
    
	// 0 output channels,
	// 1 input channels
	// 44100 samples per second
	// BUFFER_SIZE samples per buffer
	// 4 num buffers (latency)
    
    ofSetVerticalSync(true);
	ofSetCircleResolution(80);
	ofBackground(54, 54, 54);
    
	ofSoundStreamListDevices();
	
	AudioIn.setDeviceID(1);
    AudioIn.setup(this, 0, 1, 44100, BUFFER_SIZE, 4);
    AudioIn.start();
    
    
	peakTime =15; // hold longer
    decayRate = 0.95f; // decay slower
    HiGain = 0.9f; // reduced gain at lowest frequency
    LowGain = 0.01f; // increasing gain at higher frequencies
    
    avg_power  = 0.0f;
    
	Channel01_Analyzer.setup(44100, BUFFER_SIZE/2, 2);
	
	Channel01_Analyzer.peakHoldTime = peakTime;
	Channel01_Analyzer.peakDecayRate = decayRate;
	Channel01_Analyzer.linearEQIntercept = HiGain;
	Channel01_Analyzer.linearEQSlope = LowGain;
	    
	ofSetVerticalSync(true);
    
    for (int i = 0; i < Channel01_Analyzer.nAverages; i++){
        float tmp;
        Channel01_holdFreq.push_back(tmp);
        Channel01_deltaFreq.push_back(tmp);
	}
    
    
    //------- acelerometers ------
    
    //create the socket and bind to port 11999
    
    udpConnection.Create();
    udpConnection.Bind(11999);
    udpConnection.SetNonBlocking(true);
    
    //second connection on port 11998
    udpConnection2.Create();
    udpConnection2.Bind(11998);
    udpConnection2.SetNonBlocking(true);

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void testApp::audioReceived 	(float * input, int bufferSize, int nChannels){
	// samples are "interleaved"
	for (int i = 0; i < bufferSize; i++){
		Channel01[i] = input[i*2];
	}
    
    Channel01_Aubio.processAudio(Channel01, BUFFER_SIZE);
}

//--------------------------------------------------------------

void testApp::audioAnalisys(){
    
    /* do the FFT on Channel 1  */
    Channel01_fft.powerSpectrum(2, (int) BUFFER_SIZE / 2, Channel01, BUFFER_SIZE, & Channel01_magnitude[0], & Channel01_phase[0], & Channel01_power[0], & avg_power);
    
    for (int i = 0; i < (int)(BUFFER_SIZE / 2); i++) {
        Channel01_freq[i] = Channel01_magnitude[i];
    }
    
    Channel01_Analyzer.calculate(Channel01_freq);
    
    /* init attack detection on Channel 02*/
    float tmp02 = 0;
    
    /* init attack detection on Channel 01*/
    float tmp01 = 0;
    
    for (int i = 0; i < Channel01_Analyzer.nAverages; i++) {
        
        if (Channel01_Analyzer.averages[i] > Channel01_holdFreq[i]) {
            Channel01_deltaFreq[i] = Channel01_Analyzer.averages[i] - Channel01_holdFreq[i];
        }
        
        Channel01_holdFreq[i] = Channel01_Analyzer.averages[i];
        tmp01 = tmp01 + Channel01_deltaFreq[i];
        
    }
    
    tmp01 = tmp01 / Channel01_Analyzer.nAverages;
    Channel01_att = tmp01 * 0.5 + Channel01_att * 0.5;
    
    if (Channel01_peakPitch < Channel01_Aubio.pitch && Channel01_Aubio.confidence > 0.5) {
        Channel01_peakPitch = Channel01_Aubio.pitch;
    }
    
    Channel01_UsefulPitch = Channel01_Aubio.pitch * Channel01_Aubio.confidence + Channel01_UsefulPitch * (1 - Channel01_Aubio.confidence);
    
}

//-------------------------------------------------------
void testApp::SentMessages(){
    
    
    ofxOscMessage Channel01;
    Channel01.setAddress("/Channel01/AudioAnalysis");
    Channel01.addFloatArg(Channel01_Aubio.amplitude);
    Channel01.addFloatArg(Channel01_UsefulPitch);
    Channel01.addFloatArg(Channel01_att);
    Sender.sendMessage(Channel01);
    
    
    ofxOscMessage FFT01;
    FFT01.setAddress("/Channel01/FFT");
    FFT01.addIntArg(Channel01_Analyzer.nAverages);
    for (int i = 0; i < Channel01_Analyzer.nAverages; i++){
        FFT01.addFloatArg(Channel01_Analyzer.averages[i]);
    }
    Sender.sendMessage(FFT01);

}

