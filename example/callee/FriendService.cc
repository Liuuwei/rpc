#include "FriendService.h"

#include <iostream>

bool FriendService::GetFriendList(uint32_t id) {
    return true;
}

void FriendService::GetFriendList(google::protobuf::RpcController* controller, const ::fixbug::GetFriendRequest* request,
                       fixbug::GetFriendResponse* response, google::protobuf::Closure* done) {
    int32_t id = request->id();
    bool get = GetFriendList(id);
    response->set_success(get);
    response->set_errcode(0);
    done->Run();
}