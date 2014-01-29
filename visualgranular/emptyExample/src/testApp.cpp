#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	camWidth 		= 1024;	// try to grab at this size. 
	camHeight 		= 768;
	
	vidGrabber.setVerbose(true);
	vidGrabber.initGrabber(camWidth,camHeight);
	
	videoInverted 	= new unsigned char[camWidth*camHeight*3];
	videoTexture.allocate(camWidth,camHeight, GL_RGB);
    brushRadius = 5;
}


//--------------------------------------------------------------
void testApp::update(){
	
	ofBackground(100,100,100);
	
	vidGrabber.grabFrame();
	
	if (vidGrabber.isFrameNew()){
//		int totalPixels = camWidth*camHeight*3;
		unsigned char * pixels = vidGrabber.getPixels();
//		for (int i = 0; i < totalPixels; i++){
//                videoInverted[i] = pixels[currentPixel];
//                videoInverted[i+1] = pixels[currentPixel+1];
//                videoInverted[i+2] = pixels[currentPixel+2];
//                
//                w=width
//                h=height
//                p=pixel
//                r=radius
//                for(0->r)::p+(w*r)->p+(w*r)+r, p+(w*r)->p+(w*r)-r
//                for(0->r)::p-(w*r)->p-(w*r)+r, p-(w*r)->p-(w*r)-r
//            for(int j=0;j<brushRadius;j++){
//                for(int k=0;k<brushRadius;k++){
//                    plus_high = currentPixel+(camWidth*j)+k;
//                    plus_low = currentPixel+(camWidth*j)-k;
//                    videoInverted[plus_high] = pixels[plus_high];
//                    videoInverted[plus_high+1] = pixels[plus_high+1];
//                    videoInverted[plus_high+2] = pixels[plus_high+2];
//                    videoInverted[plus_low] = pixels[plus_low];
//                    videoInverted[plus_low+1] = pixels[plus_low+1];
//                    videoInverted[plus_low+2] = pixels[plus_low+2];
//                }
//                for(int k=0;k<brushRadius;k++){
//                    minus_high = currentPixel-(camWidth*j)+k;
//                    minus_low = currentPixel-(camWidth*j)-k;
//                    videoInverted[minus_high] = pixels[minus_high];
//                    videoInverted[minus_high+1] = pixels[minus_high+1];
//                    videoInverted[minus_high+2] = pixels[minus_high+2];
//                    videoInverted[minus_low] = pixels[minus_low];
//                    videoInverted[minus_low+1] = pixels[minus_low+1];
//                    videoInverted[minus_low+2] = pixels[minus_low+2];
//                }
//            }
//            i+=2;

            
//            cout<<(yMouse*camWidth*3) + (xMouse*3)<<"||";
//            if(i%index==0 && i+2 < totalPixels){
//                videoInverted[i] = pixels[index];
//                videoInverted[i+1] = pixels[index+1];
//                videoInverted[i+2] = pixels[index+2];
//            }

//            if(i>=camWidth*3 && i%(camWidth*3) != 0 && (i+1)%(camWidth*3) !=0 && i<(camWidth*3*(camHeight-1))){
//                if(i%(int)(xMouse*yMouse*3) == 0){
                    // red
//                    if((xMouse*yMouse*3)+2<totalPixels){
//                        videoInverted[i] = pixels[xMouse*yMouse*3];
//                        videoInverted[i+1] = pixels[(xMouse*yMouse*3)+1];
//                        videoInverted[i+2] = pixels[(xMouse*yMouse*3)+2];
//                    }
//                    videoInverted[i] = pixels[xMouse*yMouse*3];
//                    videoInverted[i+1] = pixels[(xMouse*yMouse*3)+1];
//                    videoInverted[i+2] = pixels[(xMouse*yMouse*3)+2];
//                    i += 2;
//                }
//                } else if ((i-1)%(xMouse*yMouse*3) == 0){
//                    // green
//                    videoInverted[i-1] = pixels[xMouse*yMouse*3];
//                    videoInverted[i+1] = pixels[(xMouse*yMouse*3)+2];
//                    videoInverted[i] = pixels[(xMouse*yMouse*3)+1];
//                    i += 1;
//                } else if((i-2)%(xMouse*yMouse*3) == 0){
//                    // blue
//                    videoInverted[i-2] = pixels[xMouse*yMouse*3];
//                    videoInverted[i] = pixels[(xMouse*yMouse*3)+2];
//                    videoInverted[i-1] = pixels[(xMouse*yMouse*3)+1];
//                }
//                videoInverted[i] = pixels[xMouse*yMouse*3];
//                videoInverted[i+1] = pixels[(xMouse*yMouse*3)+1];
//                videoInverted[i+2] = pixels[(xMouse*yMouse*3)+2];
//            }
//			videoInverted[i] = 255 - pixels[i];
//		}
//		videoTexture.loadData(videoInverted, camWidth,camHeight, GL_RGB);
	}
//
//    sprintf(eventString, "mouseMoved = (%i,%i)", xMouse, yMouse);
//
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetHexColor(0xffffff);
//	vidGrabber.draw(20,20);
	videoTexture.draw(0,0,camWidth,camHeight);
//	ofSetHexColor(0x444342);
//	ofDrawBitmapString(eventString, 600, 300);
//    cout<<currentPixel<<"||";
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	// in fullscreen mode, on a pc at least, the 
	// first time video settings the come up
	// they come up *under* the fullscreen window
	// use alt-tab to navigate to the settings
	// window. we are working on a fix for this...
	
	if (key == 's' || key == 'S'){
		vidGrabber.videoSettings();
	}
	
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    xMouse = x;
    yMouse = y;
    if(xMouse<0){
        xMouse = 0;
    } else if(xMouse>ofGetWidth()){
        xMouse = ofGetWidth();
    }
    if(yMouse<0){
        yMouse = 0;
    } else if(yMouse>ofGetHeight()){
        yMouse = ofGetHeight();
    }
//    xMouse = (int)ofMap(xMouse, 0, ofGetWidth(), 0, camWidth);
//    yMouse = (int)ofMap(yMouse, 0, ofGetHeight(), 0, camHeight);
//    currentPixel = (yMouse*camWidth*3) + (xMouse*3);
//    yMouse = (int)ofMap(yMouse, 0, ofGetHeight(), 0, camHeight);
    if(xMouse>(1+brushRadius)&&yMouse>(1+brushRadius)&&xMouse<ofGetWidth()-(1+brushRadius)&&yMouse<ofGetHeight()-(1+brushRadius)){
        currentPixel = (yMouse*camWidth*3) + (xMouse*3);
        unsigned char * pixels = vidGrabber.getPixels();
        for(int j=0;j<brushRadius;j++){
            for(int k=0;k<brushRadius;k++){
                plus_high = currentPixel+((camWidth*j)+k)*3;
                plus_low = currentPixel+((camWidth*j)-k)*3;
                minus_high = currentPixel-((camWidth*j)+k)*3;
                minus_low = currentPixel-((camWidth*j)-k)*3;
                videoInverted[plus_high] = pixels[plus_high];
                videoInverted[plus_high+1] = pixels[plus_high+1];
                videoInverted[plus_high+2] = pixels[plus_high+2];
                videoInverted[plus_low] = pixels[plus_low];
                videoInverted[plus_low+1] = pixels[plus_low+1];
                videoInverted[plus_low+2] = pixels[plus_low+2];
                videoInverted[minus_high] = pixels[minus_high];
                videoInverted[minus_high+1] = pixels[minus_high+1];
                videoInverted[minus_high+2] = pixels[minus_high+2];
                videoInverted[minus_low] = pixels[minus_low];
                videoInverted[minus_low+1] = pixels[minus_low+1];
                videoInverted[minus_low+2] = pixels[minus_low+2];
            }
        }
        videoTexture.loadData(videoInverted, camWidth,camHeight, GL_RGB);  
    }
}


//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    xMouse = x;
    yMouse = y;
    if(xMouse<0){
        xMouse = 0;
    } else if(xMouse>ofGetWidth()){
        xMouse = ofGetWidth();
    }
    if(yMouse<0){
        yMouse = 0;
    } else if(yMouse>ofGetHeight()){
        yMouse = ofGetHeight();
    }
    xMouse = (int)ofMap(xMouse, 0, ofGetWidth(), 0, camWidth);

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
        unsigned char * pixels = vidGrabber.getPixels();
            for(int j=0;j<brushRadius;j++){
                for(int k=0;k<brushRadius;k++){
                    plus_high = currentPixel+(camWidth*j)+k;
                    plus_low = currentPixel+(camWidth*j)-k;
                    videoInverted[plus_high] = pixels[plus_high];
                    videoInverted[plus_high+1] = pixels[plus_high+1];
                    videoInverted[plus_high+2] = pixels[plus_high+2];
                    videoInverted[plus_low] = pixels[plus_low];
                    videoInverted[plus_low+1] = pixels[plus_low+1];
                    videoInverted[plus_low+2] = pixels[plus_low+2];
                }
                for(int k=0;k<brushRadius;k++){
                    minus_high = currentPixel-(camWidth*j)+k;
                    minus_low = currentPixel-(camWidth*j)-k;
                    videoInverted[minus_high] = pixels[minus_high];
                    videoInverted[minus_high+1] = pixels[minus_high+1];
                    videoInverted[minus_high+2] = pixels[minus_high+2];
                    videoInverted[minus_low] = pixels[minus_low];
                    videoInverted[minus_low+1] = pixels[minus_low+1];
                    videoInverted[minus_low+2] = pixels[minus_low+2];
                }
            }
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
