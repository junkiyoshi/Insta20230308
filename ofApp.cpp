#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofSetColor(255);
	ofSetLineWidth(1.5);
}
//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	auto radius = 150;
	int deg_span = 6;

	auto target_deg = ofGetFrameNum() % 360;
	for (int deg = 0; deg < 360; deg += deg_span) {

		auto location = glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), 0);
		auto target_location = glm::vec3(radius * cos(target_deg * DEG_TO_RAD), radius * sin(target_deg * DEG_TO_RAD), 0);
		auto distance = glm::distance(location, target_location);

		auto len = 20;
		if (distance < 60) {
			
			len = ofMap(distance, 0, 60, 60, 20);
		}

		auto location_1 = glm::vec3((radius + len * 0.5) * cos(deg * DEG_TO_RAD), (radius + len * 0.5) * sin(deg * DEG_TO_RAD), 0);
		auto location_2 = glm::vec3((radius - len * 0.5) * cos(deg * DEG_TO_RAD), (radius - len * 0.5) * sin(deg * DEG_TO_RAD), 0);

		ofDrawLine(location_1, location_2);
		ofDrawSphere(location_1, 2);
		ofDrawSphere(location_2, 2);

		ofDrawSphere(target_location, 8);
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}