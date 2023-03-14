#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255);
    cells.push_back(vector<int>());
    cells[0] = {1,0,1,0,0,0,0,1,0,1,1,1,0,0,0,1,1,1,0,0,0,1};
    ruleset = {0,1,0,1,1,0,1,0};
    //std::cout << cells[0][0] << endl;
    ofSetFrameRate(5);
    ofSeedRandom(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    int gridsize = 20;
    int margin = 50;
    
    if (generation*gridsize < ofGetHeight()) {
        for (int j = 0; j < generation+1; j++){
            for (int i = 0; i < cells[0].size(); i++){
                if (cells[j][i] == 0) ofSetColor(255);
                else ofSetColor(0);
                ofDrawRectangle(i*gridsize - gridsize, j*gridsize, gridsize, gridsize);
            }
        }
    } else {
        int extra = 1 + ((generation*gridsize - ofGetHeight())/gridsize);
        //std::cout << extra << endl;
        for (int j = 0; j < generation+1; j++){
            for (int i = 0; i < cells[0].size(); i++){
                if (cells[j][i] == 0) ofSetColor(255);
                else ofSetColor(0);
                ofDrawRectangle(i*gridsize - gridsize, (j-extra)*gridsize, gridsize, gridsize);
            }
        }
    }
    
    generation++;
    cells.push_back(vector<int>());
    
    cells[generation].push_back(cells[generation-1][0]);

    for (int i = 1; i < cells[0].size()-1; i++){

        int left = cells[generation-1][i-1];
        int middle = cells[generation-1][i];
        int right = cells[generation-1][i+1];

        int newstate = rules(left,middle,right);

        cells[generation].push_back(newstate);
    }

    cells[generation].push_back(cells[generation-1][cells[0].size()]);
    
    int rule = ofMap(max(mouseX, 0), 0, 400, 0, 15);
    
    if      (rule == 0) ruleset = {0,0,0,1,1,1,1,0};
    else if (rule == 1) ruleset = {0,1,1,1,1,1,1,0};
    else if (rule == 2) ruleset = {0,0,1,1,0,1,1,0};
    else if (rule == 3) ruleset = {1,0,0,1,0,1,1,0};
    else if (rule == 4) ruleset = {0,0,1,1,1,1,0,0};
    else if (rule == 5) ruleset = {1,0,0,1,1,1,1,0};
    else if (rule == 6) ruleset = {0,0,1,1,1,1,1,0};
    else if (rule == 7) ruleset = {1,0,1,1,0,1,1,0};
    else if (rule == 8) ruleset = {0,1,0,1,1,0,1,0};
    else if (rule == 9) ruleset = {1,0,1,1,1,1,0,0};
    else if (rule == 10) ruleset = {0,1,0,1,1,1,1,0};
    else if (rule == 11) ruleset = {1,0,1,1,1,1,1,0};
    else if (rule == 12) ruleset = {0,1,1,0,0,1,1,0};
    else if (rule == 13) ruleset = {0,1,1,0,1,1,1,0};
    else if (rule == 14) ruleset = {0,1,1,1,1,0,1,0};
    else if (rule == 15) ruleset = {1,1,1,1,1,0,1,0};

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

//--------------------------------------------------------------
int ofApp::rules(int a, int b, int c){
    if      (a == 1 && b == 1 && c == 1) return ruleset[0];
    else if (a == 1 && b == 1 && c == 0) return ruleset[1];
    else if (a == 1 && b == 0 && c == 1) return ruleset[2];
    else if (a == 1 && b == 0 && c == 0) return ruleset[3];
    else if (a == 0 && b == 1 && c == 1) return ruleset[4];
    else if (a == 0 && b == 1 && c == 0) return ruleset[5];
    else if (a == 0 && b == 0 && c == 1) return ruleset[6];
    else if (a == 0 && b == 0 && c == 0) return ruleset[7];
    return 0;
}
