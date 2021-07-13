/*
* File generated automatically. Please do not modify
*/

#include "Camera_Remote.h"


extern map<string ,string > Camera_configuration;
const map<string ,string > Camera_Remote_configuration = Camera_configuration;


// Additional configuration string

const map<string ,string > Camera_Additional_Remote_configuration = {
	{"rem_s0" , "{\"RIE_Impl\":\"Camera_Remote\", \"urlSink\" : \"urlRemote_Camera_Comp1_base\" , \"RIE_Impl_Remote\" : \"s0\" }"}
};

Camera_Remote::Camera_Remote() {
	urlSink="urlRemote";
	isStopChecked=false;
	isRegistered=false;
	linkComponent();
}
Camera_Remote::Camera_Remote(string val) : RIEComponent(val) {
	urlSink="urlRemote";
	isStopChecked=false;
	isRegistered=false;
	linkComponent();
}
Camera_Remote::~Camera_Remote() {
	_prov_0.closeRemoteInterface();
	deRegisterComponent(true);
}
string Camera_Remote::readQualities() {
	RIEMessage trace;
	string buffer;

	trace.write(string("urlSink"),urlSink);
	buffer=runTimeManager.readQualities();
	if(buffer!="") {
		trace.write(string("RemoteComp"),buffer);
	}
	return trace.toString();
}
bool Camera_Remote::assignSetPoint(string s) {

	if(configurations.find(s) == configurations.end()) {
		return false;
	}else {
		RIEMessage conf;
 		string buffer;
 		setpoint=s;
 		if(!conf.parse(configurations[s])) {
 			return false;
 		} else {
 			bool r=true;
 			r &= conf.read(string("urlSink"),buffer);
 			if(buffer!=urlSink) {
 				_prov_0.closeRemoteInterface();
 				runTimeManager.closeRemoteInterface();
			}
			urlSink=buffer;
			_prov_0.setRemoteCompURL( urlSink );
 			runTimeManager.setRemoteCompURL( urlSink );
			if(conf.read(string("RIE_Impl_Remote"),buffer)) {
 				r &= runTimeManager.assignSetPoint(buffer);
			}
			return r;
 		}
	}
	return true;
}

void Camera_Remote::run() {
		isStopChecked=false;
		registerComponent();
		runTimeManager.run();
}
bool Camera_Remote::stop() {
	_prov_0.closeRemoteInterface();
	if(!isStopChecked) {
		isStopChecked=runTimeManager.stop();
	};
	return isStopChecked;
}
void Camera_Remote::stopRemote() {
	_prov_0.closeRemoteInterface();
	runTimeManager.stopRemote();
	deRegisterComponent(false);
}
void Camera_Remote::remove() {
	_prov_0.closeRemoteInterface();
	runTimeManager.remove();
	deRegisterComponent(false);
	isStopChecked=false;
}
bool Camera_Remote::isStopped() {
	if(!isStopChecked) {
		isStopChecked=runTimeManager.isStopped();
	}
	return isStopChecked;
}
void Camera_Remote::linkComponent() {
	RIE_RESET_SERVICE();
	RIE_PROV_REMOTE_SERVICE(I_Image,_prov_0, I_Image);
	RIE_REMOTE_STREAM(_prov_0);
	_prov_0.setRemoteInterface("I_Image");
	runTimeManager.setRemoteInterface("RIERuntimeInterface");
	runTimeManager.setExecuteAndClose(true);
	initializate("libFitoptivis","Camera_Remote",Camera_Remote_configuration,"");
	registerComponent();
}
void Camera_Remote::registerComponent() {
	_prov_0.setRemoteCompURL(urlSink);
	runTimeManager.setRemoteCompURL(urlSink);
	isRegistered=true;
}
void Camera_Remote::deRegisterComponent(bool isFull) {
	if(!isRegistered) return;
	isRegistered=false;
	_prov_0.closeRemoteInterface();
}
