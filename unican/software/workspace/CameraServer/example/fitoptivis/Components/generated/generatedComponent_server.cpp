//Generated DNS server
#include <iostream>
#include <RIE.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <semaphore.h>
#include <unistd.h>


using namespace std;
using namespace RIE_Methodology;

#include "component.h"

void generatedComponent_server(string IPServer, int portServer) {
	RIEComponentServer cserver(IPServer,portServer);
	bool ret;

	remoteSystem sys;
	ret=cserver.startServer();
	if(!ret) {
		cout << " Component server: cannot start" << endl;
	}
		ret=cserver.stopServer();
	if(!ret) {
		cout << " Component server: cannot stop" << endl;
	}
}
