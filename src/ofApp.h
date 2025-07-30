#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	private:
		vector<ofVec2f> ControlPoint; // ����_�̈ʒu
		int				ControlNum; // ����_�̌�
		int				PointIndex = -1; // ����_�̔ԍ��擾�i-1�Ȃ瓮�삵�Ȃ��j
		float			PointSize; // �_�̃T�C�Y
		

		float			interval; // �x�W�G�̊Ԋu
		int				width, height, widthOffset, heightOffset; // ��ʃT�C�Y
		int				endX; // �I�_��x���W
		ofVec2f			offset; // ��ʃT�C�Y�̃I�t�Z�b�g
		
		bool							MODE2 = false; // ����_�̈�����ύX����ϐ�
		vector<pair<ofVec2f, ofVec2f>>	MODE2Point;
		int								MODE2Num;

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
		ofVec2f Bezier_MODE2(float);
		
};
