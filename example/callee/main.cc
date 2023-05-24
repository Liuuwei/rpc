#include "RpcApplication.h"
#include "User.pb.h"
#include "Friend.pb.h"
#include "RpcProvider.h"
#include "FriendService.h"
#include "UserService.h"


int main(int argc, char *argv[]) {
    RpcApplication::Init(argc, argv);
    RpcProvider provider;
    provider.NotifyService(new UserService());
    provider.NotifyService(new FriendService());
    provider.Run();
}