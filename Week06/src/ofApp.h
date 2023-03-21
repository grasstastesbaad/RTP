#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

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
    
    ofImage img_1;
    ofImage img_2;
    ofImage img_3;
    ofImage img_4;
    ofImage img_5;
    ofImage img_6;
    
    ofImage inside_1;
    ofImage outside_1;
    ofImage inside_2;
    ofImage outside_2;

    ofImage inside_3;
    ofImage outside_3;
    ofImage inside_4;
    ofImage outside_4;
    
    ofImage screenshot;
    
    void generate ( ofImage & emptyimg, int cubesize, int margin);
    void generate_contour ( ofImage & emptycontour);
    
    void inside_contour( ofImage & imgSrc, ofImage & imgDest, ofImage & countour, int color);
    void outside_contour( ofImage & imgSrc, ofImage & imgDest, ofImage & contour, int color);
    
    
};
