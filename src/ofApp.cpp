#include "ofApp.h"
int bgColor = 255;
int timer = 0;  //タイマー

Boolean incMode = false;
Boolean isPlaying;
Boolean isMove;

ofSoundPlayer sound;

//--------------------------------------------------------------
void ofApp::setup(){
    // Limit drawing to a sane rate
    ofSetVerticalSync(true);
    ofSetFrameRate(30);
    
    receiver.setup(PORT);
    
    ofBackground(220, 220, 220);
    
    // Load a movie file
    player.loadMovie("movies/1.mov");
    player1.loadMovie("movies/2.mov");
    player2.loadMovie("movies/9.mov");
    player3.loadMovie("movies/3.mov");
    player4.loadMovie("movies/4.mov");
    player5.loadMovie("movies/5.mov");
    player6.loadMovie("movies/6.mov");
    player7.loadMovie("movies/7.mov");
    player8.loadMovie("movies/8.mov");
    player9.loadMovie("movies/0.mov");
    player10.loadMovie("movies/10.mov");
    
    
    player.setLoopState(OF_LOOP_NONE);
    player1.setLoopState(OF_LOOP_NONE);
    player2.setLoopState(OF_LOOP_NONE);
    player3.setLoopState(OF_LOOP_NONE);
    player4.setLoopState(OF_LOOP_NONE);
    player5.setLoopState(OF_LOOP_NONE);
    player6.setLoopState(OF_LOOP_NONE);
    player7.setLoopState(OF_LOOP_NONE);
    player8.setLoopState(OF_LOOP_NONE);
    player9.setLoopState(OF_LOOP_NONE);
    player10.setLoopState(OF_LOOP_NONE);
    
    // Start playback
    player.play();
    player1.play();
    player2.play();
    player3.play();
    player4.play();
    player5.play();
    player6.play();
    player7.play();
    player8.play();
    player9.play();
    player10.play();
    
    sound.setLoop(true);
    sound.loadSound("meganeandbob_s.mp3");
    
    //sound.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(bgColor, 200, 210);
    
    if (incMode) {
        bgColor++;
    } else {
        bgColor--;
    }
    
    if (bgColor == 0) {
        incMode = true;
    }
    if (bgColor == 255) {
        incMode = false;
    }
    
    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        if (m.getAddress() == "/one") {
            if (player.getIsMovieDone()) {
                player.setPosition(0);
            }
            isPlaying = true;
            isMove = true;
        } else if (m.getAddress() == "/two") {
            if (player1.getIsMovieDone()) {
                player1.setPosition(0);
            }
            isPlaying = true;
            isMove = true;
        } else if (m.getAddress() == "/three") {
            if (player2.getIsMovieDone()) {
                player2.setPosition(0);
            }
            isPlaying = true;
            isMove = true;
        } else if (m.getAddress() == "/four") {
            if (player3.getIsMovieDone()) {
                player3.setPosition(0);
            }
            isPlaying = true;
            isMove = true;
        }else if (m.getAddress() == "/five") {
            if (player4.getIsMovieDone()) {
                player4.setPosition(0);
            }
            isPlaying = true;
            isMove = true;
        } else if (m.getAddress() == "/six") {
            if (player5.getIsMovieDone()) {
                player5.setPosition(0);
            }
            isPlaying = true;
            isMove = true;
        } else if (m.getAddress() == "/seven") {
            if (player6.getIsMovieDone()) {
                player6.setPosition(0);
            }
            isPlaying = true;
            isMove = true;
        }else if (m.getAddress() == "/eight") {
            if (player7.getIsMovieDone()) {
                player7.setPosition(0);
            }
            isPlaying = true;
            isMove = true;
        } else if (m.getAddress() == "/nine") {
            if (player8.getIsMovieDone()) {
                player8.setPosition(0);
            }
            isPlaying = true;
            isMove = true;
        } else if (m.getAddress() == "/ten") {
            if (player9.getIsMovieDone()) {
                player9.setPosition(0);
            }
            isPlaying = true;
            isMove = true;
        }else if (m.getAddress() == "/eleven") {
            if (player10.getIsMovieDone()) {
                player10.setPosition(0);
            }
            isPlaying = true;
            isMove = true;
        }
    }
    
    ofSoundUpdate();
    
    // Signal the player to update
    player.update();
    player1.update();
    player2.update();
    player3.update();
    player4.update();
    player5.update();
    player6.update();
    player7.update();
    player8.update();
    player9.update();
    player10.update();
    
    if (!isMove) {
        timer++;
    } else {
        timer = 0;
    }
    
    cout << timer << endl;
    if(timer > (15 * 30)){
        cout << "Stop" << endl;
        timer = 0;
        sound.stop();
        sound.unloadSound();
        sound.loadSound("meganeandbob_s.mp3");
        isPlaying = false;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    // Draw the frame
    ofSetColor(255, 255, 255);
    player.draw(0,  0, ofGetWidth(), ofGetHeight());
    player1.draw(0, 0, ofGetWidth(), ofGetHeight());
    player2.draw(0, 0, ofGetWidth(), ofGetHeight());
    player3.draw(0, 0, ofGetWidth(), ofGetHeight());
    player4.draw(0, 0, ofGetWidth(), ofGetHeight());
    player5.draw(0, 0, ofGetWidth(), ofGetHeight());
    player6.draw(0, 0, ofGetWidth(), ofGetHeight());
    player7.draw(0, 0, ofGetWidth(), ofGetHeight());
    player8.draw(0, 0, ofGetWidth(), ofGetHeight());
    player9.draw(0, 0, ofGetWidth(), ofGetHeight());
    player10.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    // Draw the FPS display
    ofSetColor(20,20,20);
    
    isMove = false;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '0') {
        if (player.getIsMovieDone()) {
            player.setPosition(0);
        }
        
        if (!isPlaying){
            sound.play();
            isPlaying = true;
        }
        isMove = true;
    }
    
    if (key == '1') {
        if (player1.getIsMovieDone()) {
            player1.setPosition(0);
        }
        if (!isPlaying){
            sound.play();
            isPlaying = true;
        }
        isMove = true;
    }
    
    if (key == '2') {
        if (player2.getIsMovieDone()) {
            player2.setPosition(0);
        }
        if (!isPlaying){
            sound.play();
            isPlaying = true;
        }
        isMove = true;
    }
    
    if (key == '3') {
        if (player3.getIsMovieDone()) {
            player3.setPosition(0);
        }
        if (!isPlaying){
            sound.play();
            isPlaying = true;
        }
        isMove = true;
        
    }
    if (key == '4') {
        if (player4.getIsMovieDone()) {
            player4.setPosition(0);
        }
        if (!isPlaying){
            sound.play();
            isPlaying = true;
        }
        isMove = true;
    }
    
    if (key == '5') {
        if (player5.getIsMovieDone()) {
            player5.setPosition(0);
        }
        if (!isPlaying){
            sound.play();
            isPlaying = true;
        }
        isMove = true;
    }
    
    if (key == '6') {
        if (player6.getIsMovieDone()) {
            player6.setPosition(0);
        }
        if (!isPlaying){
            sound.play();
            isPlaying = true;
        }
        isMove = true;
    }
    
    if (key == '7') {
        if (player7.getIsMovieDone()) {
            player7.setPosition(0);
        }
        if (!isPlaying){
            sound.play();
            isPlaying = true;
            
        }
        isMove = true;
    }
    if (key == '8') {
        if (player8.getIsMovieDone()) {
            player8.setPosition(0);
        }
        if (!isPlaying){
            sound.play();
            isPlaying = true;
            
        }
        isMove = true;
    }
    
    if (key == '9') {
        if (player9.getIsMovieDone()) {
            player9.setPosition(0);
        }
        if (!isPlaying){
            sound.play();
            isPlaying = true;
            
        }
        isMove = true;
    }
    
    if (key == 'q') {
        if (player10.getIsMovieDone()) {
            player10.setPosition(0);
        }
        if (!isPlaying){
            sound.play();
            isPlaying = true;
            
        }
        isMove = true;
    }
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
    float position = (float) x / (float) ofGetWindowWidth();
    cout << "Setting playhead to " << ofToString(position) << endl;
    player.setPosition(position);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    vector< string > fileList = dragInfo.files;
    player.loadMovie(fileList[0]);
}
