#include "system.h"


const map<string,string> System_configuration = {
	{ "s0", "{\"RIE_Impl\":\"System\",\"inst_cam\":\"s0\",\"inst_disp\":\"s0\" }"},
	{ "s1", "{\"RIE_Impl\":\"System\",\"inst_cam\":\"s1\",\"inst_disp\":\"s0\" }"},
};

void System::linkComponent() {

	initializate("fitoptivis","System",System_configuration,"");

	cam.assignID("Comp1_base");
	disp.assignID("Comp2_base");

	i_cam.setName("inst_cam");
	i_disp.setName("inst_disp");

	RIE_ASSIGN_COMP2INSTANCE(cam,i_cam);
	RIE_ASSIGN_COMP2INSTANCE(disp,i_disp);

	RIE_ASSIGN_COMP_REQINTER2INST(disp,ir1,i_cam);
}

System::System() {
	this->linkComponent();
}

System::System(string val) {
	this->linkComponent();
}
System::~System() {

}
