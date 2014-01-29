#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	
	int num = 1500;
	p.assign(num, demoParticle());
	p2.assign(num, demoParticle());
	p3.assign(num, demoParticle());
    p4.assign(num, demoParticle());

    for(int i = 0; i < p.size(); i++){
		p[i].setMode(PARTICLE_MODE_NOISE);		
		p[i].reset();
	}
    
    for(int i = 0; i < p2.size(); i++){
		p2[i].setMode(PARTICLE_MODE_ATTRACT);		
		p2[i].reset();
	}
    
    for(int i = 0; i < p3.size(); i++){
		p3[i].setMode(PARTICLE_MODE_NEAREST_POINTS);		
		p3[i].reset();
	}
    
    for(int i = 0; i < p4.size(); i++){
		p4[i].setMode(PARTICLE_MODE_REPEL);		
		p4[i].reset();
	}
    
    
	resetParticles();
    
    // 0 output channels, 
	// 2 input channels
	// 44100 samples per second
	// BUFFER_SIZE samples per buffer
	// 4 num buffers (latency)
	
	ofSoundStreamSetup(0,2,this, 44100, BUFFER_SIZE, 4);	
	
	//left = new float[BUFFER_SIZE];
	//right = new float[BUFFER_SIZE];
    
	ofSetHexColor(0x666666);
	
	
	FFTanalyzer.setup(44100, BUFFER_SIZE/2, 2);
	
	FFTanalyzer.peakHoldTime = 15; // hold longer
	FFTanalyzer.peakDecayRate = 0.95f; // decay slower
	FFTanalyzer.linearEQIntercept = 0.9f; // reduced gain at lowest frequency
	FFTanalyzer.linearEQSlope = 0.01f; // increasing gain at higher frequencies
    current = 0;
    high = 0;
    mid = 0;
    low = 0;
    scale_h = 1;
    scale_m = 1;
    scale_l = 1;
}

//--------------------------------------------------------------
void testApp::resetParticles(){

	//these are the attraction points used in the forth demo 
	attractPoints.clear();
    attractPoints.push_back( ofPoint( ofGetWidth()/2 , ofGetHeight()/2 ));
	attractPointsWithMovement = attractPoints;
	for(int i = 0; i < p3.size(); i++){
		p3[i].setAttractPoints(&attractPointsWithMovement);;
		p3[i].reset();
	}
}

//--------------------------------------------------------------
void testApp::update(){
	for(int i = 0; i < p.size(); i++){
		p[i].update();
	}
    
    for(int i = 0; i < p2.size(); i++){
		p2[i].update();
	}
    
    for(int i = 0; i < p3.size(); i++){
		p3[i].update();
	}
    
    for(int i = 0; i < p4.size(); i++){
		p4[i].update();
	}
	
//	//lets add a bit of movement to the attract points
//	for(int i = 0; i < attractPointsWithMovement.size(); i++){
//		attractPointsWithMovement[i].x = attractPoints[i].x + ofSignedNoise(i * 10, ofGetElapsedTimef() * 0.7) * 12.0;
//		attractPointsWithMovement[i].y = attractPoints[i].y + ofSignedNoise(i * -10, ofGetElapsedTimef() * 0.7) * 12.0;
//	}	
    ofBackground(80,80,20);
    current = 0;
    low = 0;
    mid = 0;
    high = 0;
    for (int i = 0; i < FFTanalyzer.nAverages; i++){
		current += FFTanalyzer.averages[i];
	}
    
    for (int i = 0; i < 8; i++){
		low += FFTanalyzer.averages[i];
        scale_l = 1+(FFTanalyzer.peaks[i]/6);
	}
    
    for (int i = 8; i < 10; i++){
		mid += FFTanalyzer.averages[i];
        scale_m = 1+(FFTanalyzer.peaks[i]/6);
	}
    
    for (int i = 10; i < 16; i++){
		high += FFTanalyzer.averages[i];
        scale_h = 1+(FFTanalyzer.peaks[i]/3);
	}
    
    high_r = ofMap(scale_h, 0, 10, 50, 255);
    high_g = ofMap(scale_m, 0, 10, 50, 255);
    high_b = ofMap(scale_l, 0, 10, 50, 255);
    
    mid_r = ofMap(scale_h, 0, 10, 50, 200);
    mid_g = ofMap(scale_m, 0, 10, 50, 150);
    mid_b = ofMap(scale_l, 0, 10, 50, 100);
    
    low_r = ofMap(scale_h, 0, 10, 0, 150);
    low_g = ofMap(scale_m, 0, 10, 50, 200);
    low_b = ofMap(scale_l, 0, 10, 100, 255);
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackgroundGradient(ofColor(60,60,60), ofColor(10,10,10));

	for(int i = 0; i < current; i++){
		p[i].draw();
	}
    
    for(int i = 0; i < low; i++){
		p2[i].changeScale(scale_l, low_r, low_g, low_b, mid_r, mid_g, mid_b, high_r, high_g, high_b);
	}
    
    for(int i = 0; i < mid; i++){
		p3[i].changeScale(scale_m, low_r, low_g, low_b, mid_r, mid_g, mid_b, high_r, high_g, high_b);
	}
    
    for(int i = 0; i < high; i++){
		p4[i].changeScale(scale_h, low_r, low_g, low_b, mid_r, mid_g, mid_b, high_r, high_g, high_b);
	}
	
	ofSetColor(190);

	ofSetColor(230);	
    
    float avg_power = 0.0f;	
    
	/* do the FFT	*/
	myfft.powerSpectrum(0,(int)BUFFER_SIZE/2, left,BUFFER_SIZE,&magnitude[0],&phase[0],&power[0],&avg_power);
    
	for (int i = 0; i < (int)(BUFFER_SIZE/2); i++){
		freq[i] = magnitude[i];
	}
	
	FFTanalyzer.calculate(freq);
	
//	ofSetHexColor(0xffffff);
//	for (int i = 0; i < (int)(BUFFER_SIZE/2 - 1); i++){
//		//ofRect(200+(i*4),600,4,-freq[i]*10.0f);
//	}
//	
//	for (int i = 0; i < FFTanalyzer.nAverages; i++){
//		ofRect(200+(i*20),600,20,-FFTanalyzer.averages[i] * 6);
//	}
//	
//	ofSetHexColor(0xff0000);
//	for (int i = 0; i < FFTanalyzer.nAverages; i++){
//		ofRect(200+(i*20),600-FFTanalyzer.peaks[i] * 6,20,-4);
//	}
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
void testApp::audioIn 	(float * input, int bufferSize, int nChannels){	
	// samples are "interleaved"
	for (int i = 0; i < bufferSize; i++){
		left[i] = input[i*2];
		right[i] = input[i*2+1];
	}
}
