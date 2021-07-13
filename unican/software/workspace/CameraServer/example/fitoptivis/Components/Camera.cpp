#include "Camera.h"

Camera::Camera(string name): RIEComponent(name) {
	linkComponent();
	cap.open(0);
}

Camera::Camera() {
	linkComponent();
	cap.open(0);
}

Camera::~Camera() {

}

map<string ,string > Camera_configuration = {
	{"s0","{\"RIE_Impl\":\"Camera\"}"},
	{"s1","{\"RIE_Impl\":\"Camera_Remote\", \"urlSink\" : \"urlRemote_Camera_Comp1_base\" , \"RIE_Impl_Remote\" : \"s0\"}"}
};
void Camera::run() {

}

bool Camera::stop() {
	return true;
}

bool Camera::isStopped() {
	return true;
}



bool Camera::assignSetPoint( string s) {
	if(configurations.find(s) == configurations.end()) {
		return false;
	} else {
		RIEMessage conf;

		if(!conf.parse(configurations[s])) {
			return false;
		} else {
			bool r=true;
			return r;
		}
	}
	return true;
}

string Camera::readQuality() {

	RIEMessage trace;


	return trace.toString();
}

void Camera::linkComponent() {


	initializate("libFitoptivis","Camera",Camera_configuration,"");

	RIE_RESET_SERVICE();
	RIE_PROV_SERVICE(I_Image);

}


void Camera::get_image(imageData &data){

	//Capture image from camera using OpenCV
	cap >> image;
	//Read image from file using OpenCV
	//image=cv::imread("img_remote_4k.jpg");

	data.w=image.cols;
	data.h=image.rows;
	data.format=image.type();
	int size=( int)(image.dataend-image.datastart);
	data.data=string((char *)&image.data[0],(char *)&image.data[size]);
	std::replace(data.data.begin(),data.data.end(),'\0',' ');

}

