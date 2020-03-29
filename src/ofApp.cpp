#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(640*2,480);
    
    gui.setup();
    gui.add(framerate.setup("framerate",10,1,120));
    gui.add(previewRate.setup("previewrate",10,1,100));
    gui.add(maxFrames.setup("maxframes",50,50,100));

    cam.setup(640,480);
    cam.update(); // otherwise this will be a blank frame
    image.setFromPixels(cam.getPixels());
    images.push_back(image);
    lastFrameTime = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::update(){
    // just show vid
    cam.update();
    if(cam.isFrameNew()){
        image.setFromPixels(cam.getPixelsRef());
    }
    // if timer > framerate, add image to array
    if (ofGetElapsedTimef() - lastFrameTime >= framerate){
        lastFrameTime = ofGetElapsedTimef();
        images.push_back(image);
    }
    // show timelapse to date
    currentTLFrame+=1/previewRate;
    if (currentTLFrame >= images.size()){
        currentTLFrame=0;
    }
    // if image array is too big, remove one from the beginning
    if (images.size()>maxFrames) {
        images.erase(images.begin()); }
}

//--------------------------------------------------------------
void ofApp::draw(){
    image.draw(0,0,640,480);
    images[floor(currentTLFrame)].draw(640,0,640,480);
    ofDrawBitmapString("# frames = " + ofToString(images.size()),640+10,10);
    gui.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
