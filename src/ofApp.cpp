#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	numberOfSavedFrames = 0;
	numberOfSavedPoints = 0;

	//This is how you would load that very same file    
	if (xmlPts.loadFile("kinectPoints_ella1.xml")) {
		
		cout << "Fichero abierto" << endl;

		xmlPts.pushTag("KinectPoints");
		
		numberOfSavedFrames = xmlPts.getNumTags("newFrame");
		
		cout << numberOfSavedFrames << endl;

		xmlPts.popTag(); //pop position
	}
	else {
		ofLogError("Position file did not load!");
	}

}

//--------------------------------------------------------------
void ofApp::update(){

	mesh.clear();

	//for (int i = 0; i < numberOfSavedFrames; i++) {

	int i = ofGetFrameNum();
	cout << "Frame_" << i << endl;

	xmlPts.pushTag("KinectPoints");

	xmlPts.pushTag("newFrame", i);

	numberOfSavedPoints = xmlPts.getNumTags("newPoint");

	for (int j = 0; j < numberOfSavedPoints; j++) {

		xmlPts.pushTag("newPoint", j);

		ofPoint p;
		p.x = xmlPts.getValue("X", 0);
		p.y = xmlPts.getValue("Y", 0);
		p.z = xmlPts.getValue("Z", 0);

		mesh.addVertex(p);

		string colorPt;
		colorPt = xmlPts.getValue("color", "000000");

		ofColor colorVertex = ofColor(ofHexToInt(colorPt));
		
		mesh.addColor(colorVertex);

		xmlPts.popTag();

	}

	xmlPts.popTag();
	xmlPts.popTag();

	// points.push_back(p);

	mesh.setMode(OF_PRIMITIVE_POINTS);

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(0);

	ofSetColor(255);
	mesh.draw();

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
