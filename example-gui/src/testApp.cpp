#include "testApp.h"

void testApp::setup(){
	cam.initGrabber(640, 480);
	
	colorsOfMovement.setup(ofVec2f(1920,1080), 30);
	
	gui.setup("Colors of Movement");
	
	ofxLabel * mixLabel = new ofxLabel();
	mixLabel->setup("Channel Mixer", "Channel Mixer", 200, 40);
	gui.add(mixLabel);
	
	ofxIntSlider * bufferSize = new ofxIntSlider("Buffer Size", 30, 1, 300);
	bufferSize->addListener(this, &testApp::onGuiIntChange);
	gui.add(bufferSize);
	
	ofxFloatSlider * red = new ofxFloatSlider("Red Position", 0, 0, 1);
	red->addListener(this, &testApp::onGuiFloatChange);
	gui.add(red);
	
	ofxFloatSlider * green = new ofxFloatSlider("Green Position", 0, 0, 1);
	green->addListener(this, &testApp::onGuiFloatChange);
	gui.add(green);
	
	ofxFloatSlider * blue = new ofxFloatSlider("Blue Position", 0, 0, 1);
	blue->addListener(this, &testApp::onGuiFloatChange);
	gui.add(blue);
	
	ofxLabel * preLabel = new ofxLabel();
	preLabel->setup("Pre Effects", "Pre Effects", 200, 40);
	gui.add(preLabel);
	
	ofxFloatSlider * gamma = new ofxFloatSlider("Gamma", 1, 0, 5);
	gamma->addListener(this, &testApp::onGuiFloatChange);
	gui.add(gamma);
	
	ofxFloatSlider * brightness = new ofxFloatSlider("Brightness", 1, 0, 5);
	brightness->addListener(this, &testApp::onGuiFloatChange);
	gui.add(brightness);
	
	ofxFloatSlider * saturation = new ofxFloatSlider("Saturation", 1, 0, 5);
	saturation->addListener(this, &testApp::onGuiFloatChange);
	gui.add(saturation);
	
	ofxFloatSlider * contrast = new ofxFloatSlider("Contrast", 1, 0, 5);
	contrast->addListener(this, &testApp::onGuiFloatChange);
	gui.add(contrast);
	
	ofxFloatSlider * hueShift = new ofxFloatSlider("Hue Shift", 0, -1, 1);
	hueShift->addListener(this, &testApp::onGuiFloatChange);
	gui.add(hueShift);
	
}

void testApp::update(){
	cam.update();
	if(cam.isFrameNew()){
		colorsOfMovement.addFrame(&cam);
	}
}

void testApp::draw(){
	colorsOfMovement.getTextureReference().draw(0,0);
	gui.draw();
	ofDrawBitmapString(ofToString(ofGetFrameRate()), 20,20);
}

void testApp::onGuiIntChange(int & value){
	colorsOfMovement.setBufferSize(gui.getIntSlider("Buffer Size"));	
}

void testApp::onGuiFloatChange(float & value){
	colorsOfMovement.setRPosition(gui.getFloatSlider("Red Position"));
	colorsOfMovement.setGPosition(gui.getFloatSlider("Green Position"));
	colorsOfMovement.setBPosition(gui.getFloatSlider("Blue Position"));
	colorsOfMovement.setGamma(gui.getFloatSlider("Gamma"));
	colorsOfMovement.setBrightness(gui.getFloatSlider("Brightness"));
	colorsOfMovement.setSaturation(gui.getFloatSlider("Saturation"));
	colorsOfMovement.setContrast(gui.getFloatSlider("Contrast"));
	colorsOfMovement.setHueShift(gui.getFloatSlider("Hue Shift"));
}

