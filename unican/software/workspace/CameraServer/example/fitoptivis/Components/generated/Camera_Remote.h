/*
* File generated automatically. Please do not modify
*/

#ifndef _INCLUDE_Camera_Remote_h
#define _INCLUDE_Camera_Remote_h
#include "../Camera.h"
#include  <iostream>
using namespace std;
using namespace RIE_Methodology;

class Camera_Remote:public Camera,
			public virtual I_Image ,
			public virtual RIEComponent {
public:

	 // Define source interfaces to connect with required interfaces

	 // Define sink interfaces to connect with provided interfaces
	RIEInterfaceSink<I_Image,I_Image_Remote> _prov_0;

	 string urlSink;
	 bool isStopChecked;
	 bool isRegistered;

	 // Define runtime methods
	RIERuntimeInterface runTimeManager;

	 // Service management
	void registerComponent();
	void deRegisterComponent(bool isFull);
 	void run();
	bool stop();
	void remove();
	bool isStopped();
	void stopRemote();

	 // Define specific methods
	bool assignSetPoint(string s);
	string readQualities();
	Camera_Remote();
	Camera_Remote(string val);
	virtual ~Camera_Remote();
private:
	void linkComponent();
};

#endif
