// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: I_Image_grpc.proto

#include "I_Image_grpc.pb.h"
#include "I_Image_grpc.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace I_Image_grpc {

static const char* I_Image_method_names[] = {
  "/I_Image_grpc.I_Image/get_image",
};

std::unique_ptr< I_Image::Stub> I_Image::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< I_Image::Stub> stub(new I_Image::Stub(channel));
  return stub;
}

I_Image::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_get_image_(I_Image_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status I_Image::Stub::get_image(::grpc::ClientContext* context, const ::I_Image_grpc::I_Image_in& request, ::I_Image_grpc::I_Image_out* response) {
  return ::grpc::internal::BlockingUnaryCall< ::I_Image_grpc::I_Image_in, ::I_Image_grpc::I_Image_out, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_get_image_, context, request, response);
}

void I_Image::Stub::experimental_async::get_image(::grpc::ClientContext* context, const ::I_Image_grpc::I_Image_in* request, ::I_Image_grpc::I_Image_out* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::I_Image_grpc::I_Image_in, ::I_Image_grpc::I_Image_out, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_get_image_, context, request, response, std::move(f));
}

void I_Image::Stub::experimental_async::get_image(::grpc::ClientContext* context, const ::I_Image_grpc::I_Image_in* request, ::I_Image_grpc::I_Image_out* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_get_image_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::I_Image_grpc::I_Image_out>* I_Image::Stub::PrepareAsyncget_imageRaw(::grpc::ClientContext* context, const ::I_Image_grpc::I_Image_in& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::I_Image_grpc::I_Image_out, ::I_Image_grpc::I_Image_in, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_get_image_, context, request);
}

::grpc::ClientAsyncResponseReader< ::I_Image_grpc::I_Image_out>* I_Image::Stub::Asyncget_imageRaw(::grpc::ClientContext* context, const ::I_Image_grpc::I_Image_in& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncget_imageRaw(context, request, cq);
  result->StartCall();
  return result;
}

I_Image::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      I_Image_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< I_Image::Service, ::I_Image_grpc::I_Image_in, ::I_Image_grpc::I_Image_out, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](I_Image::Service* service,
             ::grpc::ServerContext* ctx,
             const ::I_Image_grpc::I_Image_in* req,
             ::I_Image_grpc::I_Image_out* resp) {
               return service->get_image(ctx, req, resp);
             }, this)));
}

I_Image::Service::~Service() {
}

::grpc::Status I_Image::Service::get_image(::grpc::ServerContext* context, const ::I_Image_grpc::I_Image_in* request, ::I_Image_grpc::I_Image_out* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace I_Image_grpc

