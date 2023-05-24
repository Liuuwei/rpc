#include "RpcProvider.h"
#include "RpcApplication.h"
#include "RpcHeader.pb.h"

#include <functional>

#include <stdio.h>

using namespace std::placeholders;

void RpcProvider::NotifyService(google::protobuf::Service *service) {
    ServiceInfo serviceInfo;
    const google::protobuf::ServiceDescriptor *serviceDesc = service->GetDescriptor();

    std::string serviceName = serviceDesc->name();
    int methodCount = serviceDesc->method_count();

    for (int i = 0; i < methodCount; ++ i) {
        const google::protobuf::MethodDescriptor *methodDesc = serviceDesc->method(i);
        serviceInfo.methodMap.insert({methodDesc->name(), methodDesc});
    }

    serviceInfo.service = service;
    serviceInfoMap_.insert({serviceName, serviceInfo});
}

void RpcProvider::Run() {
    std::string ip = RpcApplication::instance().GetRpcConfig().Load("rpcserverip");
    uint16_t port = atoi(RpcApplication::instance().GetRpcConfig().Load("rpcserverport").c_str());
    InetAddress address(ip, port);

    TcpServer server(&loop_, address, "RpcProvider");
    server.setConnectionCallback(std::bind(&RpcProvider::onConnection, this, _1));
    server.setMessageCallback(std::bind(&RpcProvider::onMessage, this, _1, _2, _3));
    server.setThreadNum(8);
    server.start();
    loop_.loop();
}

void RpcProvider::onConnection(const TcpConnectionPtr &conn) {
    if(!conn->connected()) {
        conn->shutdown();
    }
}   

void RpcProvider::onMessage(const TcpConnectionPtr &conn, Buffer *buffer, Timestamp receiveTime) {
    std::string request_s = buffer->retrieveAllAsString();

    uint32_t headerSize = 0;
    request_s.copy((char *)&headerSize, 4, 0);

    std::string rpcHeader_s = request_s.substr(4, headerSize);
    rpc::RpcHeader rpcHeader;
    std::string serviceName, methodName;
    uint32_t argSize;
    if (rpcHeader.ParseFromString(rpcHeader_s)) {
        serviceName = rpcHeader.service_name();
        methodName = rpcHeader.method_name();
        argSize = rpcHeader.args_size();
    } else {
        printf("%s:%d\n", __FILE__, __LINE__);
        return ;
    }
    std::string args = request_s.substr(4 + headerSize, argSize);
    // printf("=====================================\n");
    // printf("headerSize: %d\n", headerSize);
    // printf("serviceName: %s\n", serviceName.c_str());
    // printf("methodName: %s\n", methodName.c_str());
    // printf("args: %s\n", args.c_str());
    // printf("=====================================\n");

    // * 获取service对象和method对象
    auto it = serviceInfoMap_.find(serviceName);
    if (it == serviceInfoMap_.end()) {
        printf("service is not exist\n");
        return ;
    }
    auto mit = it->second.methodMap.find(methodName);
    if (mit == it->second.methodMap.end()) {
        printf("%s's method:%s is not exist\n", serviceName.c_str(), methodName.c_str());
        return ;
    }
    
    google::protobuf::Service *service = it->second.service;
    const google::protobuf::MethodDescriptor *method = mit->second;

    // * 生成request和response
    google::protobuf::Message *request = service->GetRequestPrototype(method).New();
    if (!request->ParseFromString(args)) {
        printf("%s:%d\n", __FILE__, __LINE__);
        return ;
    }

    google::protobuf::Message *response = service->GetResponsePrototype(method).New();
    google::protobuf::Closure *done = google::protobuf::NewCallback<RpcProvider, const TcpConnectionPtr &, google::protobuf::Message *>(this, &RpcProvider::sendRpcResponse, conn, response);
    service->CallMethod(method, nullptr, request, response, done);
}

void RpcProvider::sendRpcResponse(const TcpConnectionPtr &conn, google::protobuf::Message *response) {
    std::string response_s;
    if (response->SerializeToString(&response_s)) {
        conn->send(response_s);
    } else {
        printf("%s:%d\n", __FILE__, __LINE__);
    }
}