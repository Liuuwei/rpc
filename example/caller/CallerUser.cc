#include "RpcApplication.h"
#include "RpcChannel.h"
#include "User.pb.h"
#include "Friend.pb.h"

#include <iostream>

int main(int argc, char *argv[]) {
    RpcApplication::Init(argc, argv);
    fixbug::UserServiceRpc_Stub stub(new RpcChannel);
    fixbug::LoginRequest request;
    fixbug::LoginResponse response;

    request.set_name("liuwei");
    request.set_pwd("123456");
    stub.Login(nullptr, &request, &response, nullptr);
    if (response.result().errcode() == 0) {
        if (response.success() == 1)
            std::cout << "login success" << std::endl;
        else
            std::cout << "login failed" << std::endl;
    } else {
        std::cout << "rpc login error message: " << response.result().errmsg() << std::endl;
    }


    fixbug::RegisterRequeset request_;
    fixbug::RegisterResponse response_;
    request_.set_id(927033856);
    request_.set_name("qiyu");
    request_.set_pwd("qmzh5233");

    // stub.Regis(nullptr, &request_, &response_, nullptr);
    
    // if (response.result().errcode() == 0) {
    //     if (response_.success()) {
    //         std::cout << "regis success " << std::endl;
    //     } else {
    //         std::cout << "regis failed" << std::endl;
    //     }
    // }

    fixbug::FriendService_Stub f_stub(new RpcChannel());
    fixbug::GetFriendRequest f_request;
    fixbug::GetFriendResponse f_response;
    f_request.set_id(5233);
    f_stub.GetFriendList(nullptr, &f_request, &f_response, nullptr);

    if (f_response.success()) {
        std::cout << "get success" << std::endl;
    } else {
        std::cout << "get failed" << std::endl;
    }

}