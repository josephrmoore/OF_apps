#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    totalZeros = 0;
    totalVolume = 0;
    finalVolume = 0;
    
    positive = false;
    prevPositive = false;
    trigger = false;
    triggered = 0;
    grain = 0;
    sq = false;
    soundStream.setup(this, 0, 1, 44100, 1024, 4);
    bk.r = 255;
    bk.g = 0;
    bk.b = 0;
    prevVol = 0;
    prevFreq = 0;
    freq = 0;
    squares = 0;
    r = 0;
    offset = 0;
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    w = 0;
	h = 0;	// set in update()
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
		} else if (m.getAddress() == "/wii/1/button/A"){
            sq = true;
        } else if (m.getAddress() == "/wii/1/button/B"){
            sq = false;
        }
		else
		{
			cout << "unrecognized message: " << m.getAddress() << "\n";
		}
	}

        hue = ofMap(freq, 0, 4000, 0, 360);
        brightness = ofMap(finalVolume, 0, .1, 0, 100);
        hue = (.7*hue)+(.3*bk.getHue());
        brightness = (.7*brightness)+(.3*bk.getBrightness());
        bk.r = 255;
        bk.g = 0;
        bk.b = 0;
        bk.setHue(hue);
        bk.setBrightness(brightness);
//        cout<<hue<<" "<<brightness<<" "<<squares<<" "<<ofGetElapsedTimeMillis()-triggered<<" "<<trigger<<endl;
        if(ofGetElapsedTimeMillis()>4000){
            if(ofGetElapsedTimeMillis()-triggered>4000){
                if(brightness > 50){
                    squares += 1;
                    triggered = ofGetElapsedTimeMillis();
                } else if(brightness <= 50){
                    if(squares>0){
                        squares -= 1;
                        triggered = ofGetElapsedTimeMillis();
                    }
                }
            }
        }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    bk.setSaturation(pitch*200);
//    bk.setHue(roll*200);
//    bk.setBrightness(yaw*200);
    ofBackground(bk.r, bk.g, bk.b);
    ofSetColor(255);
    ofFill();
    for(int i=squares+1;i>0;i--){
        r = (100+brightness)+(50*i);
        ofSetColor(255-(i*10)-bk.r, 255-(i*10)-bk.g, 255-(i*10)-bk.b);
        if(sq){
            sw = (ofGetWidth()/2-50-(brightness/2))-(25*i)+r/2;
            sh = (ofGetHeight()/2-50-(brightness/2))-(25*i)+r/2;
            ofEllipse(sw, sh, r, r);

        } else {
            sw = (ofGetWidth()/2-50-(brightness/2))-(25*i);
            sh = (ofGetHeight()/2-50-(brightness/2))-(25*i);
            ofRect(sw, sh, r, r);
//            ofRect((ofGetWidth()/2-50-(brightness/2))-(25*i), (ofGetHeight()/2-50-(brightness/2))-(25*i), (100+brightness)+(50*i), (100+brightness)+(50*i));
        }
    }
    if ((ofGetFrameNum() % 40) == 0) {
		cout<<printf("roll = %f, pitch = %f, yaw = %f, accel = %f\n",roll,pitch,yaw,accel)<<endl;
	}
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

void testApp::audioIn(float * input, int bufferSize, int nChannels){
    totalVolume = 0;
    totalZeros = 0;
    grain = (100.0/bufferSize);

    // adding the sum of all the squares
    
    for (int i = 0; i < bufferSize; i++){
        totalVolume += input[i]*input[i]; 
    }
    
    finalVolume = sqrt(totalVolume/bufferSize);
    brightness = ofMap(finalVolume, 0, .1, 0, 100);
    
    for (int i = 0; i < bufferSize-1; i++){
        if(input[i] < 0){
            if(input[i+1]>0){
                totalZeros++;
            }
        } else {
            if(input[i+1]<0){
                totalZeros++;
            }
        }
        
    }
    
    freq = (totalZeros/2) / (bufferSize / (float)44100);
    hue = ofMap(freq, 0, 4000, 0, 360);
    
}

