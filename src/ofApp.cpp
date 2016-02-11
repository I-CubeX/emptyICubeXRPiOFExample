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
   if (setupOrient3d()) {
      for (int i=0; i<100; i++) {
         Orient3dData data = readOrient3d();
         printf("Orient 3d: bearing %4i    pitch %4i    roll %4i\n",data.bearing, data.pitch, data.roll);
      }   
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

bool ofApp::setupOrient3d() {
    pullUpDnControl(8, PUD_UP);
    pullUpDnControl(9, PUD_UP);
    if ( (myOrient3d = wiringPiI2CSetup(0x60)) == -1) {
        printf("error initializing i2c for orient3d!\n");
        return false;
    }
    else {
        printf("orient3d: i2c init successful\n");
        return true;
    }
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

Orient3dData ofApp::readOrient3d() {
    Orient3dData res;
    res.bearing = (int)wiringPiI2CReadReg8(myOrient3d, 0x01);
    res.pitch = (int) wiringPiI2CReadReg8(myOrient3d, 0x04);
    res.roll = (int) wiringPiI2CReadReg8(myOrient3d, 0x05);
    return res;
}
