#pragma once

#include "User.pb.h"

#include <unordered_map>
#include <string>

#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>

using namespace muduo;
using namespace muduo::net;


class RpcProvider {
    public:
        // * 形参为基类
        void NotifyService(google::protobuf::Service *service);
        void Run();
    private:
        EventLoop loop_;
        struct ServiceInfo {
            google::protobuf::Service *service;
            std::unordered_map<std::string, const google::protobuf::MethodDescriptor *> methodMap;
        };
        std::unordered_map<std::string, ServiceInfo> serviceInfoMap_;
        void onConnection(const TcpConnectionPtr &conn);
        void onMessage(const TcpConnectionPtr &conn, Buffer *buffer, Timestamp receiveTime);
        // * 序列化rpc的响应及发送
        void sendRpcResponse(const TcpConnectionPtr &conn, google::protobuf::Message *);
};