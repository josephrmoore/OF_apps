#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    glEnable(GL_DEPTH_TEST);
    bIsRecording = false;
    playbackStartTime = 0;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    
    // draw the line
    ofSetColor(255);
    ofNoFill();
    ofBeginShape();
    for(vector<TimePoint>::iterator it = points.begin(); it != points.end(); it++){
        ofVertex(it->x, it->y);
    }
    ofEndShape();
    
    // draw the point at current time
    ofPoint pos = getPositionForTime(ofGetElapsedTimef()-playbackStartTime);
    ofFill();
	ofSetColor(255,0,0);
	ofCircle(pos.x, pos.y, 10);
    
//    ofPushMatrix();{
//        ofTranslate(512, 384);
//        ofRotate(ofGetElapsedTimeMillis(), 1,1,0);
//        ofTranslate(-512, -384);
//        ofBeginShape();
//        for(vector<TimePoint>::iterator it = points.begin(); it != points.end(); it++){
//            ofVertex(it->x, it->y, it->z);
//        }
//        ofEndShape();
//    };ofPopMatrix();
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
    TimePoint t;
    t.x = x;
    t.y = y;
    t.t = ofGetElapsedTimef()-startTime;
    
    points.push_back(t);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    bIsRecording = true;
    points.clear();
    startTime = ofGetElapsedTimef();

    TimePoint t;
    t.x = x;
    t.y = y;
    t.t = 0;
    
    points.push_back(t);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    bIsRecording = false;
    playbackStartTime = ofGetElapsedTimef();
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


ofPoint testApp::getPositionForTime(float time){

	
	// are we recording?
	
	if (bIsRecording == true){
		return ofPoint(0,0,0);
	} else if (points.size() < 2){
		return ofPoint(0,0,0);
	}
	
	// now, let's figure out where we are in the drawing....
	
	// (a) figure out where we are in the cycle
	
	// (like % but for floats)
	while (time > points[points.size()-1].t){
		time -= points[points.size()-1].t;
	}
	
	
	ofPoint pos;
	
	for (int i = 0; i < points.size()-1; i++){
		if (time >= points[i].t && time < points[i+1].t){
			
			// calculate pct:
			
			float part = time - points[i].t;
			float whole = points[i+1].t - points[i].t;
			float pct = part / whole;
			
			// figure out where we are between a and b
			
			
			pos.x = (1-pct) * points[i].x + (pct) * points[i+1].x;
			pos.y = (1-pct) * points[i].y + (pct) * points[i+1].y;
			
			
		}
	}
	
	return pos;
    
//    ofPoint p;
//    if(bIsRecording || points.size()<2){
//        return p;
//    }
//    
//    while(time>points[points.size()-1].t){
//        time -= points[points.size()-1].t;
//    }
//    
//    for(int i=0; i<points.size(); i++){
//        if(time>= points[i].t && time<points[i+1].t){
//            float part = time-points[i].t;
//            float whole = points[i+1].t - points[i].t;
//            float pct = part/whole;
//            
//            p.x = 1-pct * points[i].x + pct * points[i+1].x;
//            p.y = 1-pct * points[i].y + pct * points[i+1].y;
//        }
//    }
//    return p;
    
}