#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//This is how you would load that very same file    
	if (xmlPts.loadFile("kinectPoints_ella1.xml")) {
		
		xmlPts.pushTag("KinectPoints");
		
		int numberOfSavedFrames = xmlPts.getNumTags("frame");
		
		for (int i = 0; i < numberOfSavedFrames; i++) {
		
			xmlPts.pushTag("frame", i);

			int numberOfSavedPoints = xmlPts.getNumTags("newPoint");

			for (int j = 0; j < numberOfSavedPoints; j++) {

				xmlPts.pushTag("newPoint", j);

				ofPoint p;
				p.x = xmlPts.getValue("X", 0);
				p.y = xmlPts.getValue("Y", 0);
				p.z = xmlPts.getValue("Z", 0);

				string colorPt;
				colorPt = xmlPts.getValue("color", "000000");
				xmlPts.popTag();

			}

			xmlPts.popTag();

			// points.push_back(p);
		}

		xmlPts.popTag(); //pop position
	}
	else {
		ofLogError("Position file did not load!");
	}

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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
