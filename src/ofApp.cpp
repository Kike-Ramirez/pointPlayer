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

	camera.setTarget(ofVec3f(0, 0, 900));

}

//--------------------------------------------------------------
void ofApp::update(){

	puntos.clear();
	colores.clear();

	//for (int i = 0; i < numberOfSavedFrames; i++) {

	int i = ofGetFrameNum();

	xmlPts.pushTag("KinectPoints");

	xmlPts.pushTag("newFrame", i);

	numberOfSavedPoints = xmlPts.getNumTags("newPoint");
	
	for (int j = 0; j < numberOfSavedPoints; j++) {


		ofVec3f p;
		p.x = xmlPts.getAttribute("newPoint", "x", 0.0, j);
		p.y = xmlPts.getAttribute("newPoint", "y", 0.0, j);
		p.z = xmlPts.getAttribute("newPoint", "z", 0.0, j);


		puntos.push_back(p);

		string colorPt;

		colorPt = xmlPts.getAttribute("newPoint", "color", "000000", j);
		
		ofColor colorVertex = ofColor(ofHexToInt(colorPt));
		colores.push_back(colorVertex);
		

	}

	

	xmlPts.popTag();
	xmlPts.popTag();

	ofSetColor(255);
	ofFill();
}

//--------------------------------------------------------------
void ofApp::draw(){

	camera.begin();

	ofBackground(0);
	ofPushMatrix();
	// ofRotateY(-ofGetFrameNum());

	for (int i = 0; i < puntos.size(); i++)
	{
		ofSetColor(colores[i]);
		ofFill();
		ofDrawSphere(puntos[i], 1);
	}

	ofPopMatrix();

	camera.end();
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
