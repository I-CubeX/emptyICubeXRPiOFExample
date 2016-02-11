#pragma once

#include "ofMain.h"
#include "wiringPi.h"
#include "wiringPiSPI.h"
#include "wiringPiI2C.h"

struct Orient3dData {
	int bearing;
	int pitch;
	int roll;
};

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

	private:		
		bool setupSensors();
		int readADC(int adcnum);
		bool setupOrient3d();
                Orient3dData readOrient3d();
		int myOrient3d;
};
