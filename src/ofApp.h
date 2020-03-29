#pragma once

#include "ofMain.h"
#include "ofVideoGrabber.h"
#include "ofImage.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
    ofVideoGrabber cam;
    ofImage image;
    ofxFloatSlider framerate;
    ofxFloatSlider previewRate;
    ofxIntSlider maxFrames;

    ofxPanel gui;
    vector<ofImage> images;
    
    
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
    private:
    float lastFrameTime;
    float currentTLFrame = 0;
};