#include "fitoptivis.h"

#include "Components/system.h"


using namespace RIE_Methodology;


int myMain(char *file);


int main(int narg, char *arg[]){

	int ret;
	char *dat;

	if(narg>1) {
		dat=arg[1];
	} else {
		dat=0;
	}

	ret=myMain(dat);
	return ret;
}
