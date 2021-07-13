/*
* File generated automatically. Please do not modify
*/

#include "Camera_RemoteServer.h"


const map<string ,string > Camera_RemoteServer_configuration = {
		{"s0" ,"{\"RemoteInstance\" : \"s0\", \"urlSink\" : \"urlLocal_Camera_Comp1_base\"} "}
		};

Camera_RemoteServer::Camera_RemoteServer() {
	urlSink="urlLocal";
runTimeManager.setComponent(this);
	linkComponent();
}
Camera_RemoteServer::Camera_RemoteServer(string val) : RIEComponent(val) {
	urlSink="urlLocal";
runTimeManager.setComponent(this);
	linkComponent();
}
Camera_RemoteServer::~Camera_RemoteServer() {
		runTimeManager.removeGlobalServerList(this->ID,"RIERuntimeInterface");
		runTimeManager.closeLocalInterface();
		deRegisterComponent(true);
	}
bool Camera_RemoteServer::assignSetPoint(string s) {

	if(configurations.find(s) == configurations.end()) {
	return false;
	} else {
	RIEMessage conf;
	string buffer;
	setpoint=s;
	if(!conf.parse(configurations[s])) {
	return false;
	} else {
	bool r=true;
	r &= conf.read(string("urlSink"),buffer);
	if(buffer!=urlSink) {
 			}
			urlSink=buffer;
			return r;
			}
		}
	return true;
}
void Camera_RemoteServer::linkComponent() {
	_prov_0.setRemoteInterface("I_Image");
	runTimeManager.setComponent(this);
	runTimeManager.setRemoteInterface("RIERuntimeInterface");
	runTimeManager.setExecuteAndClose(true);

	remoteComponent.assignID("remoteComp");
	remoteInstance.setName("RemoteInstance");
	RIE_ASSIGN_COMP2INSTANCE(remoteComponent,remoteInstance);
	isRegistered=false;

	RIE_RESET_SERVICE();
	RIE_REMOTE_SOURCE2INST(_prov_0, remoteInstance);
	initializate("libFitoptivis","Camera_RemoteServer",Camera_RemoteServer_configuration,"");
}
void Camera_RemoteServer::registerComponent() {
		_prov_0.updateGlobalServerList(this->ID,"I_Image","Camera_RemoteServer");
		runTimeManager.insertGlobalServerList(this->ID,"RIERuntimeInterface","Camera_RemoteServer");
	runTimeManager.CompName=this->ID;
	isRegistered=true;
}
void Camera_RemoteServer::deRegisterComponent(bool isFull) {
	if(!isRegistered) return;
	isRegistered=false;
		_prov_0.closeLocalInterface();
		if(isFull)
			_prov_0.removeGlobalServerList(this->ID,"I_Image");
}
