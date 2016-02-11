#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
   printf("\n\nhello world from simple i-cubex rpi sensors example\n\n");
   setupSensors();
   for (int i=0; i<100; i++) {
      printf("ANALOG sensors: ");
      for (int s=0; s<8; s++) {
         printf("%4i ",readADC(s));
      }
      printf("\n");
   }
   printf("\n\ntest complete. exiting app...\n");
   ofExit();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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

bool ofApp::setupSensors() {
    if (wiringPiSPISetup (0, 1000000) < 0)
        return false;
    else
        return true;

}

int ofApp::readADC(int adcnum)
{
    uint8_t buff[3];
    int adc;
    if ((adcnum > 7) || (adcnum < 0))
        return -1;
    buff[0] = 1;
    buff[1] = (8+adcnum)<<4;
    buff[2] = 0;
    wiringPiSPIDataRW(0, buff, 3);
    adc = ((buff[1]&3) << 8) + buff[2];
    return adc;
}
