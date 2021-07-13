// Generated DNS server
#include <iostream>
#include <RIE.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;
using namespace RIE_Methodology;

void generatedDNS_server(string fileName, int portServer) {


	if(portServer== -1) {
		portServer=DEFAULT_RIEDNS_PORT;
	}
	RIEDNSServer dns(((string)"0.0.0.0"),portServer);
	bool ret;

	if(fileName=="") {
		fileName="generatedDNSList.data";
	}
	int dnsal;
	dnsal=dns.loadData(fileName);
	if(dnsal <= 0){
		cout << endl <<  " Cannot load dns file " << fileName << " Code= " << dnsal << endl;
	}

	dns.isCached=true;

	ret=dns.startDNS();
	if(!ret){
		cout << " DNS server: cannot start. File= " << fileName << endl;
	}
		ret=dns.stopDNS();
	if(!ret) {
		cout << " DNS server: cannot stop" << endl;
	}
}
