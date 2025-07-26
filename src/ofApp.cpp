#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	width = ofGetWidth();
	height = ofGetHeight();
	widthOffset = width / 2;
	heightOffset = height / 2;
	offset = ofVec2f(widthOffset, heightOffset);
	endX = width;

	PointSize = 20.0;
	interval = 0.01;
	ControlNum = 2;
	ControlPoint.resize(ControlNum);

	for (int i = 0; i < ControlNum; i++) {
		if (i == 0) {
			ControlPoint[i] = ofVec2f(0, height);
		}
		else if (i == ControlNum - 1) {
			ControlPoint[i] = ofVec2f(endX, 0);
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
	width = ofGetWidth();
	height = ofGetHeight();
}

//--------------------------------------------------------------
float ofApp::Bernstein(int n, int i, float t) {
	return binomialcoefficient(n, i) * std::pow(t, i) * std::pow((1 - t), (n - i));
}

//--------------------------------------------------------------
int ofApp::binomialcoefficient(int n, int i) {
	// 問題が起きた時用
	if (n < 0 || i < 0 || n < i) return 0;
	// = 1 になるから除外
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

	for (int i = 0; i < ControlPoint.size(); i++) {
		point += ControlPoint[i] * Bernstein(ControlPoint.size() - 1, i, t);
	}

	return point;
}

//--------------------------------------------------------------
void ofApp::draw(){
	endX = ofGetWidth();
	ControlPoint[ControlPoint.size() - 1].x = endX;

	// 始点終点制御点の描画
	for (int i = 0; i < ControlPoint.size(); i++) {
		if (i == 0 || i == ControlPoint.size() - 1) {
			ofSetColor(ofColor::red);
		}
		else {
			ofSetColor(ofColor::white);
		}
		ofDrawCircle(ControlPoint[i], PointSize);
	}

	// ベジエ曲線の描画
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
	if (button == OF_MOUSE_BUTTON_LEFT && PointIndex != -1) {
		if (x >= 0 && x <= width && y >= 0 && y <= height) {
			if (PointIndex == 0 || PointIndex == ControlPoint.size() - 1) {
				ControlPoint[PointIndex].y = y;
			}
			else {
				ControlPoint[PointIndex].set(x, y);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	// 左クリックしたとき、カーソルが点上に存在するかの判定
	// 複数重なっている場合、番号が小さい方が優先
	ofVec2f mousePosition(x, y);
	if (button == OF_MOUSE_BUTTON_LEFT) {
		for (int i = 0; i < ControlPoint.size(); i++) {
			if (mousePosition.distance(ControlPoint[i]) <= PointSize) {
				PointIndex = i;
				break;
			}
		}
	}

	if (button == OF_MOUSE_BUTTON_RIGHT) {
		ofVec2f insertPoint = ofVec2f(x, y);
		ControlPoint.insert(ControlPoint.end() - 1, insertPoint);
		ControlNum = ControlPoint.size();
	}
	else if (button == OF_MOUSE_BUTTON_MIDDLE) {
		if (ControlPoint.size() > 2) {
			ControlPoint.erase(ControlPoint.end() - 1);
			ControlNum = ControlPoint.size();
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (button == OF_MOUSE_BUTTON_LEFT) {
		PointIndex = -1;
	}
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
