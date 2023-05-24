#include "RpcApplication.h"
#include "RpcHeader.pb.h"
#include "RpcChannel.h"
#include "RpcConfig.h"

#include <arpa/inet.h>
#include <assert.h>

#include <string>

void RpcChannel::CallMethod(const google::protobuf::MethodDescriptor* method, 
                            google::protobuf::RpcController* controller, 
                            const google::protobuf::Message* request, 
                            google::protobuf::Message* response, google::protobuf::Closure* done) {
    const google::protobuf::ServiceDescriptor *sd = method->service();
    std::string serviceName = sd->name();
    std::string methodName = method->name();

    uint32_t args_size = 0;
    std::string args_s;
    if (!request->SerializeToString(&args_s)) {
        printf("%s:%d\n", __FILE__, __LINE__);
        return ;
    }
    args_size = args_s.size();

    rpc::RpcHeader rpcHeader;
    rpcHeader.set_service_name(serviceName);
    rpcHeader.set_method_name(methodName);
    rpcHeader.set_args_size(args_size);

    uint32_t header_size = 0;
    std::string rpcHeader_s;
    if (!rpcHeader.SerializeToString(&rpcHeader_s)) {
        printf("%s:%d\n", __FILE__, __LINE__);
        return ;
    }
    header_size = rpcHeader_s.size();

    std::string send;
    send.insert(0, (char *)&header_size, 4);
    send += rpcHeader_s;
    send += args_s;

    RpcConfig config_ = RpcApplication::instance().GetRpcConfig();

    int clientFd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(config_.Load("rpcserverport").c_str()));
    inet_pton(AF_INET, config_.Load("rpcserverip").c_str(), &addr.sin_addr);

    int ret = ::connect(clientFd, (sockaddr *)&addr, sizeof(addr));
    assert(ret != -1);
    int n = 0;
    while (n < send.size()) {
        int len = ::send(clientFd, send.c_str() + n, send.size() - n, 0);
        if (len <= 0)break;
        n += len;
    }

    std::vector<char> buf(1024);
    n = ::recv(clientFd, &*buf.begin(), buf.size(), 0);
    std::cout << n << std::endl;
    
    if (!response->ParseFromArray(&*buf.begin(), n)) {
        printf("%s:%d\n", __FILE__, __LINE__);
    }
}