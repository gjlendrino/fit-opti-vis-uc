#ifndef interface_I_Image_Remote
#define interface_I_Image_Remote
#include "../datatypes.h"

#include "I_Image.h"
#include <grpcpp/grpcpp.h>
#include "../grpc/I_Image_grpc.grpc.pb.h"
#include "../grpc/I_Image_grpc.pb.h"

#include <RIE.h>

using namespace RIE_Methodology;

#include <string>

class I_Image_Remote: public I_Image, public RIEInterfaceRemote, public I_Image_grpc::I_Image::Service{
public:


	//grpc remote service
	Status get_image(ServerContext* context, const I_Image_grpc::I_Image_in* request,I_Image_grpc::I_Image_out* reply) override;
	virtual void get_image(imageData &data);
	virtual bool localService(int serviceCode, RIESerializer &argIn, RIESerializer &argOut);
	virtual bool localService(void *argIn, void *argOut);

	void openServer(string address,int port){
		//Open Server
		server=new RIEgRPCServer(address,port,this);
		server->run_server();
	}


	virtual ~I_Image_Remote();
};



#endif