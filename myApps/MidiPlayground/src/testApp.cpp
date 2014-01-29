#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofBackground(0);
    
    gui = new ofxUICanvas;
    gui->addLabel("MIDI Playground");
    gui->addSpacer();
    gui->setColorBack(ofColor(255,100));
    gui->setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(255,100));
    gui->addSlider("note", 0, 127, 64);
    gui->addSlider("velocity", 0, 127, 64);
//    gui->addSlider("control change", 0, 127, 64);
    gui->addSlider("program change", 0, 127, 64);
    gui->addSlider("pitch bend", 0, 127, 64);
    gui->addSlider("aftertouch", 0, 127, 64);
//    gui->addSlider("polyaftertouch", 0, 127, 64);
    
    ofAddListener(gui->newGUIEvent,this,&testApp::onGuiEvent);
    
    gui->loadSettings("guiSettings.xml");
    
    
    // ofxMidi stuff
    
    // print the available output ports to the console
	midiOut.listPorts(); // via instance
	//ofxMidiOut::listPorts(); // via static too
	
	// connect
	midiOut.openPort(0);	// by number
	//midiOut.openPort("IAC Driver Pure Data In");	// by name
	//midiOut.openVirtualPort("ofxMidiOut");		// open a virtual port
	
	channel = 1;
	program = 0;
	note = 0;
	velocity = 127;
	pan = 0;
	pitch = 0;
	aftertouch = 0;
	polytouch = 0;
    metronome = true;
    root = 0;
    
    ofxGamepadHandler::get()->enableHotplug();
	
	//CHECK IF THERE EVEN IS A GAMEPAD CONNECTED
	if(ofxGamepadHandler::get()->getNumPads()>0){
        ofxGamepad* pad = ofxGamepadHandler::get()->getGamepad(0);
        ofAddListener(pad->onAxisChanged, this, &testApp::axisChanged);
        ofAddListener(pad->onButtonPressed, this, &testApp::buttonPressed);
        ofAddListener(pad->onButtonReleased, this, &testApp::buttonReleased);
	}
    
}

//--------------------------------------------------------------

void testApp::axisChanged(ofxGamepadAxisEvent& e)
{
	cout << "AXIS " << e.axis << " VALUE " << ofToString(e.value) << endl;
	midiOut.sendPitchBend(channel, e.value*120);
}

void testApp::buttonPressed(ofxGamepadButtonEvent& e)
{
    if(e.button == 4){
        root = 0;
    }
    if(e.button == 5){
        root = 1;
    }
    if(e.button == 6){
        root = 2;
    }
    if(e.button == 7){
        root = 3;
    }
    if(e.button == 8){
        root = 4;
    }
    if(e.button == 9){
        root = 5;
    }
    if(e.button == 10){
        root = 6;
    }
    if(e.button == 11){
        root = 7;
    }
    if(e.button == 12){
        midiOut.sendNoteOn(channel, 36+root,  velocity);
    }
    if(e.button == 13){
        midiOut.sendNoteOn(channel, 40+root,  velocity);
    }
    if(e.button == 14){
        midiOut.sendNoteOn(channel, 43+root,  velocity);
    }
    if(e.button == 15){
        midiOut.sendNoteOn(channel, 48+root,  velocity);
    }
	cout << "BUTTON " << e.button << " PRESSED" << endl;
}

void testApp::buttonReleased(ofxGamepadButtonEvent& e)
{
    if(e.button == 8){
        midiOut << NoteOff(channel, 24, velocity); // stream interface
    }
    if(e.button == 9){
        midiOut << NoteOff(channel, 36, velocity); // stream interface
    }
    if(e.button == 10){
        midiOut << NoteOff(channel, 48, velocity); // stream interface
    }
    if(e.button == 11){
        midiOut << NoteOff(channel, 60, velocity); // stream interface
    }
    if(e.button == 12){
        midiOut << NoteOff(channel, 28, velocity); // stream interface
    }
    if(e.button == 13){
        midiOut << NoteOff(channel, 32, velocity); // stream interface
    }
    if(e.button == 14){
        midiOut << NoteOff(channel, 40, velocity); // stream interface
    }
    if(e.button == 15){
        midiOut << NoteOff(channel, 44, velocity); // stream interface
    }
	cout << "BUTTON " << e.button << " RELEASED" << endl;
}


void testApp::exit() {
	// clean up
	midiOut.closePort();
    gui->saveSettings("guiSettings.xml");
    delete gui;
}

void testApp::onGuiEvent(ofxUIEventArgs &e) {
    
    
    string name = e.widget->getName();
	int kind = e.widget->getKind();
    
    if( name == "on/off"){
        
        ofxUIButton *myButton = (ofxUIButton *)e.widget;
        
        if( myButton->getValue() == 0){
            // note off
        } else {
            // note on
        }
        
    } else if( name == "note" ){
        ofxUISlider *noteslider = (ofxUISlider *)e.widget;
        note = noteslider->getScaledValue();
        cout << "Got a message! " << name << " - " << noteslider->getValue() << endl;
    } else if( name == "velocity" ){
        ofxUISlider *velslider = (ofxUISlider *)e.widget;
        velocity = velslider->getScaledValue();
        cout << "Got a message! " << name << " - " << velslider->getValue() << endl;
    } else if( name == "program change" ){
        ofxUISlider *progslider = (ofxUISlider *)e.widget;
        program = progslider->getScaledValue();
        cout << "Got a message! " << name << " - " << progslider->getValue() << endl;
    } else if( name == "pitch bend" ){
        ofxUISlider *pitchslider = (ofxUISlider *)e.widget;
        pitch = pitchslider->getScaledValue();
        cout << "Got a message! " << name << " - " << pitchslider->getValue() << endl;
    } else if( name == "aftertouch" ){
        ofxUISlider *afterslider = (ofxUISlider *)e.widget;
        aftertouch = afterslider->getScaledValue();
        cout << "Got a message! " << name << " - " << afterslider->getValue() << endl;
    }
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
	ofxGamepadHandler::get()->draw(10,140);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    midiOut.sendNoteOn(channel, note,  velocity);
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    midiOut << NoteOff(channel, note, velocity); // stream interface
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
