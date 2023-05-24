#include "UserService.h"

bool UserService::Login(std::string name, std::string pwd) {
    if (name == "liuwei" && pwd == "123456")
        return true;
    return false;
}

bool UserService::Regis(uint32_t id, std::string name, std::string pwd) {
    return true;
}
void UserService::Login(google::protobuf::RpcController* controller, const ::fixbug::LoginRequest* request,
                        fixbug::LoginResponse* response, google::protobuf::Closure* done) {
    std::string name = request->name();
    std::string pwd = request->pwd();  

    bool login_result = Login(name, pwd);
    fixbug::ResultCode *rcode = response->mutable_result();
    if (login_result) {
        response->set_success(true);
        rcode->set_errcode(0);
        rcode->set_errmsg("");
    } else {
        response->set_success(false);
        rcode->set_errcode(0);
        rcode->set_errmsg("");
    }

    done->Run();
}

void UserService::Regis(google::protobuf::RpcController* controller, const ::fixbug::RegisterRequeset* request,
                        fixbug::RegisterResponse* response, google::protobuf::Closure* done) {

    uint32_t id = request->id();
    std::string name = request->name();
    std::string pwd = request->pwd();
    bool regis_result = Regis(id, name, pwd);
    response->set_success(regis_result);
    response->mutable_result()->set_errcode(0);
    response->mutable_result()->set_errmsg("");

    done->Run();
}