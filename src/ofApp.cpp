#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(camW*2,camH);
    saveButton.addListener(this, &ofApp::saveButtonPressed);

    gui.setup();
    gui.add(framerate.setup("period of frame capture (s)",10,1,400));
    gui.add(previewRate.setup("framerate of preview (f)",10,1,100));
    gui.add(maxFrames.setup("max frames in loop (#)",50,50,100));
    gui.add(saveButton.setup("save current timelapse to disk"));

    cam.setup(camW,camH);
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
    image.draw(0,0,camW,camH); // show live cam input
    images[floor(currentTLFrame)].draw(camW,0,camW,camH); // show timelapsed
    ofDrawBitmapString("# frames = " + ofToString(images.size()),camW+10,10);
    ofDrawBitmapString("current frame " + ofToString(currentTLFrame),camW+10,20);
    gui.draw();
    
}

//--------------------------------------------------------------
void ofApp::saveButtonPressed(){
    // save current timelapse array to disk as a gif
    gifEncoder.setup(camW,camH, .25, 256);
    for (int i=0; i<images.size(); i++){
        gifEncoder.addFrame(images[i], 0.25);
    }
    gifEncoder.save("tloutput_" + ofToString(lastFrameTime) + ".gif");
    gifEncoder.reset();
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
