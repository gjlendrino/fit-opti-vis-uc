#include "Display.h"

Display::Display(string name): RIEComponent(name) {
	isActive=false;
	hilo=0;
	linkComponent();
}

Display::Display() {
	isActive=false;
	hilo=0;
	linkComponent();
}

Display::~Display() {
	if(hilo!=0 && isActive) {
		pthread_cancel(hilo_native);
	}
	hilo=0;
	isActive=false;
}

map<string ,string > Display_configuration = {
	{"s0","{\"RIE_Impl\":\"Display\"}"}
};
void Display::run() {

	hilo = new thread(&Display::execFunc,this);
	hilo->detach();

}

bool Display::stop() {
	return true;
}

bool Display::isStopped() {
return true;
}



bool Display::assignSetPoint( string s) {
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

string Display::readQuality() {

	RIEMessage trace;


	return trace.toString();
}

void Display::linkComponent() {


	initializate("libFitoptivis","Display",Display_configuration,"");

	RIE_RESET_SERVICE();
	RIE_REQ_SERVICE(ir1);

}

void Display::execFunc(){

	while(1){
		ir1.service()->get_image(image);
		cv::Mat img(image.h,image.w,image.format, (unsigned char *)image.data.c_str());
		if(!img.empty()){
			cv::imshow("Camera Display",img);
			cv::waitKey(1);
		}
	}

}



