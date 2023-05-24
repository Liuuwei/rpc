#include "test.pb.h"

#include <iostream>
#include <string>

using namespace fixbug;
using namespace google::protobuf;

int main() {
    GetFriendListResponse rsp;
    ResultCode *rc = rsp.mutable_result();
    rc->set_errcoed(0);
    User *user1 = rsp.add_friend_list();
    user1->set_name("ha");
    user1->set_age(22);
    user1->set_sex(User::MAN);

    

    std::cout << rsp.friend_list_size();
}
