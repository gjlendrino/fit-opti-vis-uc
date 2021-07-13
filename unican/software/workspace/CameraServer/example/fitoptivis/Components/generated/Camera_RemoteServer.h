/*
* File generated automatically. Please do not modify
*/

#ifndef _INCLUDE_Camera_RemoteServer_h
#define _INCLUDE_Camera_RemoteServer_h
#include "../Camera.h"
#include  <iostream>
using namespace std;
using namespace RIE_Methodology;

class Camera_RemoteServer : 	public virtual RIEComponent {
public:

	 // Define source interfaces to connect with provided interfaces
	RIEInterfaceSource<I_Image,I_Image_Remote> _prov_0;

	 // Define sink interfaces to connect with required interfaces

	 string urlSink;
	 bool isRegistered;
	 // Define runtime methods
	RIERuntimeInterface runTimeManager;

	 // Define remote components
	RIEInstance remoteInstance;
	Camera	remoteComponent;

	 // Service management
	void registerComponent();
	void deRegisterComponent(bool isFull);
 	void run() {
		registerComponent();
		}
	bool stop(){
		return true;
		}
	void resume(){
		registerComponent();
		}
	void remove(){
		deRegisterComponent(false);
		}
	void stopRemote(){
		deRegisterComponent(false);
		}
	bool isStopped() {
		return true;
		}

	 // Define internal methods
	bool assignSetPoint(string s);
	string readQualities();
	Camera_RemoteServer();
	Camera_RemoteServer(string val);
	virtual ~Camera_RemoteServer();
private:
	void linkComponent();
};

#endif
