#ifndef _INCLUDE_remoteSystem_h
#define _INCLUDE_remoteSystem_h

#include <RIE.h>
#include "component.h"
class remoteSystem : public RIEComponent { 
public:
#include "compListRemoteSystem.h"
remoteSystem() {
	ID="remoteSystem";
	linkComponent();
};
remoteSystem(string val) : RIEComponent(val) {
	linkComponent();
};
~remoteSystem()  { 
};
private:
	void linkComponent() {
		#include "linkRemoteSystem.h"
	}
};
#endif
