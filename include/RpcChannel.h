#pragma once

#include "User.pb.h"

class RpcChannel : public google::protobuf::RpcChannel {
    public:
        virtual void CallMethod(const google::protobuf::MethodDescriptor* method, 
                                google::protobuf::RpcController* controller, 
                                const google::protobuf::Message* request, 
                                google::protobuf::Message* response, google::protobuf::Closure* done) override;
};