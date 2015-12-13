#pragma once

#include "ofMain.h"
#include "ofxHapPlayer.h"
#include "ofxOsc.h"

#define PORT 3334

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
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxHapPlayer player;
    ofxHapPlayer player1;
    ofxHapPlayer player2;
    ofxHapPlayer player3;
    ofxHapPlayer player4;
    ofxHapPlayer player5;
    ofxHapPlayer player6;
    ofxHapPlayer player7;
    ofxHapPlayer player8;
    ofxHapPlayer player9;
    ofxHapPlayer player10;
    
    ofxOscReceiver receiver;
};
