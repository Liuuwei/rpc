#pragma once

#include "User.pb.h"
#include "RpcApplication.h"
#include "RpcProvider.h"

#include <string>
#include <iostream>


class UserService : public fixbug::UserServiceRpc {
    public:
        bool Login(std::string name, std::string pwd);

        bool Regis(uint32_t id, std::string name, std::string pwd);
        void Login(google::protobuf::RpcController* controller, const ::fixbug::LoginRequest* request,
                   fixbug::LoginResponse* response, google::protobuf::Closure* done) override;

        void Regis(google::protobuf::RpcController* controller, const ::fixbug::RegisterRequeset* request,
                   fixbug::RegisterResponse* response, google::protobuf::Closure* done) override;
};