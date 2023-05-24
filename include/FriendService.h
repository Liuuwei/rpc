#pragma once

#include "Friend.pb.h"

class FriendService : public fixbug::FriendService {
    public:
        bool GetFriendList(uint32_t id);
        void GetFriendList(google::protobuf::RpcController* controller, const ::fixbug::GetFriendRequest* request,
                       fixbug::GetFriendResponse* response, google::protobuf::Closure* done) override;
};