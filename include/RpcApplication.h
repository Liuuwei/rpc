#pragma once

#include "RpcConfig.h"

// * 框架基础类，负责初始化操作
class RpcApplication {
    public:
        static void Init(int argc, char *argv[]);
        static RpcApplication& instance();
        RpcConfig& GetRpcConfig();
    private:
        static RpcConfig config_;
        RpcApplication() {}
        RpcApplication(const RpcApplication&) = delete;
        RpcApplication(RpcApplication&&) = delete;
};