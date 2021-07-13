#ifndef fitoptivis_component_System
#define fitoptivis_component_System

#include "../fitoptivis.h"

class System: public RIEComponent {
public:
	//Component instances
	Camera cam;
	Display disp;

	//RIE instances
	RIEInstance i_cam;
	RIEInstance i_disp;

	System();
	System(string val);
	virtual ~System();

private:
	 void linkComponent();
};

#endif
