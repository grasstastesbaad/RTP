#include "ofApp.h"
void ofApp::generate_contour ( ofImage & emptycontour){
    emptycontour.allocate(450, 300, OF_IMAGE_GRAYSCALE);
    for (int i = 0; i < 450; i++){
        for (int j = 0; j < 300; j++){
            emptycontour.setColor(i,j,127);
        }
    }
    emptycontour.update();
}
//-------------------------------
void ofApp::inside_contour( ofImage & imgSrc, ofImage & imgDest, ofImage & contour, int color){
    
    ofImage edgeimage;
    edgeimage.allocate(imgSrc.getWidth(), imgSrc.getHeight(), OF_IMAGE_GRAYSCALE);
    
    ofImage temp_img;
    temp_img.allocate(img_1.getWidth(), img_1.getHeight(), OF_IMAGE_GRAYSCALE);
    
    for (int i = 0; i < imgSrc.getWidth(); i++){
        for (int j = 0; j < imgSrc.getHeight(); j++){
            temp_img.setColor(i,j, imgSrc.getColor(i, j));
        }
    }
    
    for (int i = 0; i < imgSrc.getWidth(); i++){
        for (int j = 0; j < imgSrc.getHeight(); j++){
            edgeimage.setColor(i, j, 127);
        }
    }
    
    for (int i = 0; i < imgSrc.getWidth(); i++){
        for (int j = 0; j < imgSrc.getHeight(); j++){
            if (contour.getColor(i, j).getBrightness() != 127){
                temp_img.setColor(i,j,0);
            }
        }
    }
    
    for (int i = 0; i < temp_img.getWidth(); i++){
        for (int j = 0; j < temp_img.getHeight(); j++){
            
            //neighbors
            
            //edges
            int i_m_1 = ofClamp(i-1, 0, temp_img.getWidth()-1);
            int i_p_1 = ofClamp(i+1, 0, temp_img.getWidth()-1);
            int j_m_1 = ofClamp(j-1, 0, temp_img.getHeight()-1);
            int j_p_1 = ofClamp(j+1, 0, temp_img.getHeight()-1);
            
            //neighor values
            ofColor self = temp_img.getColor(i,j);
            ofColor n_ = temp_img.getColor(i,j_m_1);
            ofColor ne = temp_img.getColor(i_p_1,j_m_1);
            ofColor e_ = temp_img.getColor(i_p_1,j);
            ofColor se = temp_img.getColor(i_p_1,j_p_1);
            ofColor s_ = temp_img.getColor(i,j_m_1);
            ofColor sw = temp_img.getColor(i_m_1,j_p_1);
            ofColor w_ = temp_img.getColor(i_m_1,j);
            ofColor nw = temp_img.getColor(i_m_1,j_m_1);
            
            if (temp_img.getColor(i, j).getBrightness() == 255){
                if (  n_.getBrightness() < 127 ||
                      ne.getBrightness() < 127 ||
                    e_.getBrightness() < 127 ||
                    se.getBrightness() < 127 ||
                    s_.getBrightness() < 127 ||
                    sw.getBrightness() < 127 ||
                    w_.getBrightness() < 127 ||
                    nw.getBrightness() < 127 ) {
                    edgeimage.setColor(i, j, color);
                }
            }
        }
    }
    
    for (int i = 0; i < imgSrc.getWidth(); i++){
        for (int j = 0; j < imgSrc.getHeight(); j++){
            if (edgeimage.getColor(i, j).getBrightness() != 127){
                imgDest.setColor(i, j, color);
            }
        }
    }
    imgDest.update();
    
}
//--------------------------------------------------
void ofApp::outside_contour( ofImage & imgSrc, ofImage & imgDest, ofImage & contour, int color){
    
    ofImage edgeimage;
    edgeimage.allocate(imgSrc.getWidth(), imgSrc.getHeight(), OF_IMAGE_GRAYSCALE);
    
    ofImage temp_img;
    temp_img.allocate(img_1.getWidth(), img_1.getHeight(), OF_IMAGE_GRAYSCALE);
    
    for (int i = 0; i < imgSrc.getWidth(); i++){
        for (int j = 0; j < imgSrc.getHeight(); j++){
            temp_img.setColor(i,j, imgSrc.getColor(i, j));
        }
    }
    
    for (int i = 0; i < imgSrc.getWidth(); i++){
        for (int j = 0; j < imgSrc.getHeight(); j++){
            edgeimage.setColor(i, j, 127);
        }
    }
    
    for (int i = 0; i < imgSrc.getWidth(); i++){
        for (int j = 0; j < imgSrc.getHeight(); j++){
            if (contour.getColor(i, j).getBrightness() != 127){
                temp_img.setColor(i,j,255);
            }
        }
    }
    
    for (int i = 0; i < imgSrc.getWidth(); i++){
        for (int j = 0; j < imgSrc.getHeight(); j++){
            
            //neighbors
            
            //edges
            int i_m_1 = ofClamp(i-1, 0, imgSrc.getWidth()-1);
            int i_p_1 = ofClamp(i+1, 0, imgSrc.getWidth()-1);
            int j_m_1 = ofClamp(j-1, 0, imgSrc.getHeight()-1);
            int j_p_1 = ofClamp(j+1, 0, imgSrc.getHeight()-1);
            
            //neighor values
            ofColor self = temp_img.getColor(i,j);
            ofColor n_ = temp_img.getColor(i,j_m_1);
            ofColor ne = temp_img.getColor(i_p_1,j_m_1);
            ofColor e_ = temp_img.getColor(i_p_1,j);
            ofColor se = temp_img.getColor(i_p_1,j_p_1);
            ofColor s_ = temp_img.getColor(i,j_m_1);
            ofColor sw = temp_img.getColor(i_m_1,j_p_1);
            ofColor w_ = temp_img.getColor(i_m_1,j);
            ofColor nw = temp_img.getColor(i_m_1,j_m_1);
            
            if (temp_img.getColor(i, j).getBrightness() == 0){
                if (  n_.getBrightness() > 127 ||
                      ne.getBrightness() > 127 ||
                    e_.getBrightness() > 127 ||
                    se.getBrightness() > 127 ||
                    s_.getBrightness() > 127 ||
                    sw.getBrightness() > 127 ||
                    w_.getBrightness() > 127 ||
                    nw.getBrightness() > 127 ) {
                    edgeimage.setColor(i, j, color);
                }
            }
        }
    }
    
    for (int i = 0; i < imgSrc.getWidth(); i++){
        for (int j = 0; j < imgSrc.getHeight(); j++){
            if (edgeimage.getColor(i, j).getBrightness() != 127){
                imgDest.setColor(i, j, color);
            }
        }
    }
    imgDest.update();
    
}
//--------------------------------------------------
void ofApp::generate ( ofImage & emptyimg, int cubesize, int margin){
    for (int i = 0; i < 450; i += 18){
        for (int j = 0; j < 300; j += cubesize){
            if (ofRandom(1)>0.6) {
                if (ofRandom(1)>0.6) {
                    for (int m = i; m < i + cubesize; m++){
                        for (int n = j; n < j + cubesize; n++){
                            emptyimg.setColor(m,n,ofColor(255));
                        }
                    }
                } else {
                    for (int m = i; m < i + cubesize + margin; m++){
                        for (int n = j; n < j + cubesize; n++){
                            emptyimg.setColor(m,n,ofColor(255));
                        }
                    }
                }
                
            }
            j += margin;
        }
        i += margin;
    }
    
    for (int i = 0; i < 450; i += cubesize){
        i += margin;
        for (int j = 0; j < 300; j += cubesize){
            j += margin;
            if (ofRandom(1)>0.6) {
                if (ofRandom(1)>0.6) {
                    for (int m = i; m < i + cubesize; m++){
                        for (int n = j; n < j + cubesize; n++){
                            emptyimg.setColor(m,n,ofColor(255));
                        }
                    }
                } else {
                    for (int m = i; m < i + cubesize; m++){
                        for (int n = j; n < j + cubesize + margin; n++){
                            emptyimg.setColor(m,n,ofColor(255));
                        }
                    }
                }
            }
        }
    }
    
    emptyimg.update();
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    //ofSetFrameRate(5);

    //img_1
    img_1.allocate(450,300,OF_IMAGE_GRAYSCALE);
    
    generate(img_1, 18, 6);
    
    //contour images
    generate_contour(inside_1);
    generate_contour(outside_1);
    generate_contour(inside_2);
    generate_contour(outside_2);
    generate_contour(inside_3);
    generate_contour(outside_3);
    generate_contour(inside_4);
    generate_contour(outside_4);
    
    //img_2
    img_2.allocate(img_1.getWidth(), img_1.getHeight(), OF_IMAGE_GRAYSCALE);
    
    for (int i = 0; i < 2; i++) inside_contour(img_1, inside_1, inside_1, 255);
    for (int i = 0; i < 2; i++) inside_contour(img_1, inside_1, inside_1, 0);
    for (int i = 0; i < 2; i++) outside_contour(img_1, outside_1, outside_1, 0);
    for (int i = 0; i < 2; i++) outside_contour(img_1, outside_1, outside_1, 255);
    
    for (int i = 0; i < img_1.getWidth(); i++){
        for (int j = 0; j < img_1.getHeight(); j++){
            if (inside_1.getColor(i, j) != 127){
                img_2.setColor(i,j, inside_1.getColor(i,j));
            } else if (outside_1.getColor(i, j) != 127){
                img_2.setColor(i,j, outside_1.getColor(i,j));
            } else img_2.setColor(i,j, img_1.getColor(i,j));
        }
    }
    img_2.update();
    
    //img_3
    img_3.allocate(img_1.getWidth(), img_1.getHeight(), OF_IMAGE_GRAYSCALE);
    
    for (int i = 0; i < 2; i++) inside_contour(img_2, inside_2, inside_2, 255);
    for (int i = 0; i < 2; i++) inside_contour(img_2, inside_2, inside_2, 0);
    for (int i = 0; i < 2; i++) outside_contour(img_2, outside_2, outside_2, 0);
    for (int i = 0; i < 2; i++) outside_contour(img_2, outside_2, outside_2, 255);
    
    for (int i = 0; i < img_1.getWidth(); i++){
        for (int j = 0; j < img_1.getHeight(); j++){
            if (inside_2.getColor(i, j) != 127){
                img_3.setColor(i,j, inside_2.getColor(i,j));
            } else if (outside_2.getColor(i, j) != 127){
                img_3.setColor(i,j, outside_2.getColor(i,j));
            } else img_3.setColor(i,j, img_2.getColor(i,j));
        }
    }
    img_3.update();
    
    //img_4
    img_4.allocate(img_1.getWidth(), img_1.getHeight(), OF_IMAGE_GRAYSCALE);
    for (int i = 0; i < 450; i++){
        for (int j = 0; j < 300; j++){
            img_4.setColor(i,j,0);
        }
    }
    generate(img_4, 6, 6);
    
    //img_5
    img_5.allocate(img_1.getWidth(), img_1.getHeight(), OF_IMAGE_GRAYSCALE);
    
    for (int i = 0; i < 1; i++) inside_contour(img_4, inside_3, inside_3, 255);
    for (int i = 0; i < 3; i++) outside_contour(img_4, outside_3, outside_3, 0);
    for (int i = 0; i < 1; i++) outside_contour(img_4, outside_3, outside_3, 255);
    
    for (int i = 0; i < img_1.getWidth(); i++){
        for (int j = 0; j < img_1.getHeight(); j++){
            if (inside_3.getColor(i, j) != 127){
                img_5.setColor(i,j, inside_3.getColor(i,j));
            } else if (outside_3.getColor(i, j) != 127){
                img_5.setColor(i,j, outside_3.getColor(i,j));
            } else img_5.setColor(i,j, 0);
        }
    }
    img_5.update();
    
    //img_6
    img_6.allocate(img_1.getWidth(), img_1.getHeight(), OF_IMAGE_GRAYSCALE);
    
    for (int i = 0; i < 1; i++) inside_contour(img_5, inside_4, inside_4, 255);
    for (int i = 0; i < 3; i++) outside_contour(img_5, outside_4, outside_4, 0);
    for (int i = 0; i < 1; i++) outside_contour(img_5, outside_4, outside_4, 255);
    for (int i = 0; i < 3; i++) outside_contour(img_5, outside_4, outside_4, 0);
    for (int i = 0; i < 1; i++) outside_contour(img_5, outside_4, outside_4, 255);
    
    for (int i = 0; i < img_1.getWidth(); i++){
        for (int j = 0; j < img_1.getHeight(); j++){
            if (inside_4.getColor(i, j) != 127){
                img_6.setColor(i,j, inside_4.getColor(i,j));
            } else if (outside_4.getColor(i, j) != 127){
                img_6.setColor(i,j, outside_4.getColor(i,j));
            } else img_6.setColor(i,j, 0);
        }
    }
    img_6.update();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    img_1.draw(10,10);
    img_2.draw(10,10 + img_1.getHeight() + 10);
    img_3.draw(10,10 + img_1.getHeight() + 10 + img_1.getHeight() + 10);
    
    img_4.draw(10 + img_1.getWidth() + 10, 10);
    img_5.draw(10 + img_1.getWidth() + 10, 10 + img_1.getHeight() + 10);
    img_6.draw(10 + img_1.getWidth() + 10, 10 + img_1.getHeight() + 10 + img_1.getHeight() + 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    screenshot.grabScreen(0, 0, 930, 940);
    screenshot.save("week05.jpg");
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
