#include "fitoptivis.h"

#include "Components/system.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <signal.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//#include <sys/wait.h>

using namespace RIE_Methodology;
using namespace std;

#define CONFIGFILE	"conflocal.conf"

void generatedDNS_server(string fileName, int portServer);
void generatedComponent_server(string ipServer,int portServer);


int mainLocal(int localServerPort) {
	// Step 1 --> Instantiate the system
	System sys;
	cout<<"System created !!"<<endl;
	// Step 2 --> Begin execution
	sys.RIEComponent::RIErun();
	cout<<"System working !!"<<endl;

	bool isWorking;
	string sal;

	isWorking=true;
	while(isWorking) {
		cout << "Press a command" << endl;
		cin >> sal;

		if(sal=="e") {				// End = finish
			isWorking=false;
		} else {
			auto sconfig=sys.configurations.find(sal);
			if(sconfig!=sys.configurations.end()) {		// Correct configuration
				cout << "Moving system to a safe state" << endl;
				if(!sys.RIEstop()) {
					while(!sys.RIEisStopped());		// Wait until the system is stopped
				}
				sys.RIEstopRemote();
				cout << "System in a safe state -> Reconfiguration start" << endl;
				sys.reconfig(sal);
				cout << "Reconfiguration end - Set point=" << sal << " -> Resume execution" << endl;
				sys.RIErun();
				cout << "System working" << endl;
			}
		}
	}

	cout<<"System end !!"<<endl;
	if(!sys.RIEstop()) {
		while(!sys.RIEisStopped());		// Wait until the system is stopped
	}
	sys.RIEremove();
	cout<<"System removed !!"<<endl;

	return 0;
}


int mainRemote(string RemoteIP,int RemotePort){
	std::thread th(generatedComponent_server,RemoteIP,RemotePort);
	th.detach();
	return 1;
}



int mainDNS(string DNSFileName,int DNSPort){
	std::thread th(generatedDNS_server,DNSFileName,DNSPort);
	th.detach();
	return 1;
}




int myMain(char *file) {
	int ret;
	char buffer[256];

	if(file==0) {
		strcpy(buffer, CONFIGFILE);
	} else {
		strcpy(buffer, file);
	}

	ret=0;
	char DNSAdress[256];
	int DNSPort;
	char DNSFile[256];	// if * a server is not created
	int RemotePort;		// -1 No crea remote port
	int localPort;		// -1 No intancia componentes y local server

	FILE *fin;
	if((fin=fopen(buffer,"r"))==0) {
		cout << " Error: Cannot read configuration file\n" << endl;
		return 1;
	}
	// Read configuration file data
	if(fscanf(fin,"%s",DNSAdress)!=1) {
		cout << "Fail read file 1" << endl;
		return 2;
	}
	cout << "DNSAdress " << DNSAdress << endl;

	if(fscanf(fin,"%d",&DNSPort)!=1) {
		cout << "Fail read file 2" << endl;
		return 2;
	}
	cout << "DNSPort " << DNSPort << endl;

	if(fscanf(fin,"%s",DNSFile)!=1) {
		cout << "Fail read file 3" << endl;
		return 2;
	}
	cout << "DNSFile " << DNSFile << endl;

	if(fscanf(fin,"%d",&RemotePort)!=1) {
		cout << "Fail read file 4" << endl;
		return 2;
	}
	cout << "RemotePort " << RemotePort << endl;

	if(fscanf(fin,"%d",&localPort)!=1) {
		cout << "Fail read file 5" << endl;
		return 2;
	}
	cout << "localPort " << localPort << endl;
	fclose(fin);


	string DNSFileName=DNSFile;
	string DNS_IP=DNSAdress;
	//define DNS
	RIE_assignDNSDefaults(DNS_IP,DNSPort);


	if(DNSFileName!="*") {
		ret=mainDNS(DNSFileName,DNSPort);
	}
	if(RemotePort!= -1) {
		ret=mainRemote(IPRemoteServer,RemotePort);
	}
	if(localPort != -1) {
		RIEComponentServer cserver(IPRemoteServer,localPort);
		thread th(&RIEComponentServer::startServer,&cserver);
		th.detach();
		ret=mainLocal(localPort);
	} else {
		string buff;

		do {
			cout << " Press \'e\' to finish execution" << endl;
			cin >> buff;
		} while(buff[0]!='e');
	}


    return ret;
}






