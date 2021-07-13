#include "I_Image_Remote.h"



#ifndef USE_GRPC
void I_Image_Remote::get_image(imageData &data){
	RIESerializer bufIn,bufOut;
	//Serialize input parameters
	//Call remote function
	if(! remoteService(1,bufIn, bufOut) ) {
		RIE_ERROR( remoteService , " Error code = ") << lastError << endl;
	}
	//De-Serialize response
}
#endif

void I_Image_Remote::get_image(imageData &data){
	//Open Remote interface
	if(!remoteService()) {
		RIE_ERROR( remoteService , " Error code = ") << lastError << endl;

	}
	I_Image_grpc::I_Image_in request;
	I_Image_grpc::I_Image_out reply;

	//Serialize input arguments

	//Execute gRPC service
	client=new RIEgRPCClient();
	//Create channel to communicate with Server
	client->target_str=interf_address+":"+to_string(interf_port);
	grpc::ChannelArguments ch_args;
	ch_args.SetMaxReceiveMessageSize(-1);

	client->channel=grpc::CreateCustomChannel(client->target_str, grpc::InsecureChannelCredentials(),ch_args);
	std::unique_ptr<I_Image_grpc::I_Image::Stub> stub_(I_Image_grpc::I_Image::NewStub(client->channel));

	//Rpc to connect with remote component server
	grpc::Status status=stub_->get_image(&client->context, request, &reply);

	//De-Serialize output arguments
	data.h=reply.h();
	data.w=reply.w();
	data.format=reply.format();
	data.data=reply.data();
}
Status I_Image_Remote::get_image(ServerContext* context, const I_Image_grpc::I_Image_in* request,I_Image_grpc::I_Image_out* reply) {

	const I_Image_grpc::I_Image_in *in=request;
	I_Image_grpc::I_Image_out *out=reply;

	localService((void *)in,out);

	return Status::OK;

}

bool I_Image_Remote::localService(int serviceCode, RIESerializer &argIn, RIESerializer &argOut) { 

	I_Image_Remote *linter;

	if(!isLocalandServer) {	// if it is a client, this function cannot be used
		 lastError= -1;
		 return false;
	 }


	linter =(I_Image_Remote *) pInterRemote->interService();
	argOut.reset();
	switch( serviceCode) {
		case 1:
			//Serialize data
			//Call local function
			//De-Serialize data
			break;
		default:
			break;
	}
	return true;
}

bool I_Image_Remote::localService(void *argIn,void *argOut) { 

	I_Image_Remote *linter;

	if(!isLocalandServer) {	// if it is a client, this function cannot be used
		 lastError= -1;
		 return false;
	 }

	linter =(I_Image_Remote *) pInterRemote->interService();

	I_Image_grpc::I_Image_out *out_data;
	out_data=(I_Image_grpc::I_Image_out *)argOut;
	//De-Serialize data
	imageData data_local;
	//Call local function
	linter->get_image(data_local);
	//Serialize data
	out_data->set_h(data_local.h);
	out_data->set_w(data_local.w);
	out_data->set_format(data_local.format);
	out_data->set_data(data_local.data);

	return true;
}
I_Image_Remote::~I_Image_Remote(){};
