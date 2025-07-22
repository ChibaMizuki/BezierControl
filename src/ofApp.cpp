#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	width = ofGetWidth();
	height = ofGetHeight();
	widthOffset = width / 2;
	heightOffset = height / 2;

	offset = ofVec2f(widthOffset, heightOffset);

	interval = 0.01;
	ControlNum = 3;
	ControlPoint.resize(ControlNum);
	for (int i = 0; i < ControlNum; i++) {
		if (i == 0) {
			ControlPoint[i] = ofVec2f(0, height);
		}
		else if (i == ControlNum - 1) {
			ControlPoint[i] = ofVec2f(width, 0);
		}
		else {
			ControlPoint[i] = 
				ofVec2f(ofRandom(-widthOffset, widthOffset), ofRandom(-heightOffset, heightOffset)) + offset;
		}
	}
	ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
float ofApp::Bernstein(int n, int i, float t) {
	return binomialcoefficient(n, i) * std::pow(t, i) * std::pow((1 - t), (n - i));
}

//--------------------------------------------------------------
int ofApp::binomialcoefficient(int n, int i) {
	// –â‘è‚ª‹N‚«‚½Žž—p
	if (n < 0 || i < 0 || n < i) return 0;
	// = 1 ‚É‚È‚é‚©‚çœŠO
	if (i == 0 || n == i) return 1;

	int result = 1;
	for (int k = 1; k <= i; k++) {
		result *= (n - k + 1);
		result /= k;
	}
	return result;
}

//--------------------------------------------------------------
ofVec2f ofApp::Bezier(float t) {
	ofVec2f point(0, 0);

	for (int i = 0; i < ControlNum; i++) {
		point += ControlPoint[i] * Bernstein(ControlNum - 1, i, t);
	}

	return point;
}

//--------------------------------------------------------------
void ofApp::draw(){
	width = ofGetWidth();
	height = ofGetHeight();
	ControlPoint[0] = ofVec2f(0, height);
	ControlPoint[ControlNum - 1] = ofVec2f(width, 0);

	for (int i = 0; i < ControlNum; i++) {
		if (i == 0 || i == ControlNum - 1) {
			ofSetColor(ofColor::red);
		}
		else {
			ofSetColor(ofColor::white);
		}
		ofDrawCircle(ControlPoint[i], 20);
	}

	ofSetColor(ofColor::green);
	for (float t = 0.0; t < 1.0; t += interval) {
		ofVec2f p0 = Bezier(t);
		ofVec2f p1 = Bezier(t + interval);
		ofDrawLine(p0, p1);
	}
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
	if (button == OF_MOUSE_BUTTON_RIGHT) {
		ofVec2f insertPoint = ofVec2f(x, y);
		ControlPoint.insert(ControlPoint.end() - 1, insertPoint);
		ControlNum = ControlPoint.size();
	}
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
