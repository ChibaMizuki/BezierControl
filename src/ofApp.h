#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	private:
		vector<ofVec2f> ControlPoint; // 制御点の位置
		int				ControlNum; // 制御点の個数
		int				PointIndex = -1; // 制御点の番号取得（-1なら動作しない）
		float			PointSize; // 点のサイズ
		

		float			interval; // ベジエの間隔
		int				width, height, widthOffset, heightOffset; // 画面サイズ
		int				endX; // 終点のx座標
		ofVec2f			offset; // 画面サイズのオフセット
		ofEasyCam		camera; 

	public:
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

		float Bernstein(int, int, float);
		int binomialcoefficient(int, int);
		ofVec2f Bezier(float);
		
};
