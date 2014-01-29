#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetCircleResolution(50);
	ofSetFrameRate(60);
	ofSetWindowShape(1280, 800);
	ofBackground(0, 0, 0);
	ofSetVerticalSync(true);
	ofEnableSmoothing();
	ofSetFullscreen(true);
	
	w = 0;
	h = 0;	// set in update()
	
	// listen on the given port
	cout << "listening for osc messages on port " << PORT << "\n";
	receiver.setup( PORT );
	
    
}

//--------------------------------------------------------------
void testApp::update(){
	// check for waiting messages
	while( receiver.hasWaitingMessages() )
	{
		if(w == 0 || h == 0){
			w = ofGetWidth();
			h = ofGetHeight();
		}
		// get the next message
		ofxOscMessage m;
		float x,y;
		receiver.getNextMessage( &m );
		
		if ( m.getAddress() == "/wii/2/ir/0" )
		{
			x = m.getArgAsFloat( 0 );
			wiiX = x * w;
			cout << "x: " << wiiX << " y: " << wiiY << "\n";
		}
		else if ( m.getAddress() == "/wii/2/ir/1" )
		{
			y = 1 - m.getArgAsFloat( 0 );
			wiiY = y * h;
			cout << "x: " << wiiX << " y: " << wiiY << "\n";
		}
		else if (m.getAddress() == "/wii/1/accel/pry/1") {
			roll = m.getArgAsFloat(0);
			
		} else if (m.getAddress() == "/wii/1/accel/pry/2") {
			yaw = m.getArgAsFloat(0);
		}
		else if (m.getAddress() == "/wii/1/accel/pry/0") {
			pitch = m.getArgAsFloat(0);
			
		} else if (m.getAddress() == "/wii/1/accel/pry/3") {
			accel = m.getArgAsFloat(0);
		}
		else
		{
			cout << "unrecognized message: " << m.getAddress() << "\n";
		}
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	if ((ofGetFrameNum() % 100) == 0) {
		printf("roll = %f, pitch = %f, yaw = %f, accel = %f\n",roll,pitch,yaw,accel);
	}
	
	ofSetColor(255, 130, 0);
	//float radius = 50;
	ofFill();
	//ofCircle(wiiX, wiiY, radius);
	ofCircle(roll *= ofGetWidth(), yaw *= ofGetHeight(),100);
	ofCircle(accel *= ofGetWidth(), pitch *= ofGetWidth(), 50);
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

