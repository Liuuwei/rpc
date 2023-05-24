#include "RpcApplication.h"

#include <unistd.h>

#include <iostream>

void showArgHelp() {
    std::cout << "format: command -i <configfile> " << std::endl;
}

RpcConfig RpcApplication::config_;

void RpcApplication::Init(int argc, char *argv[]) {
    if (argc < 2) {
        showArgHelp();
        exit(EXIT_FAILURE);
    }

    int c = 0;
    std::string config_file;
    while ( (c = getopt(argc, argv, "i:")) != -1) {
        switch (c) {
            case 'i':
                config_file = optarg;
                break;
            case '?':
            case ':':
                showArgHelp();
                exit(EXIT_FAILURE);
            default:
                break;
        }
    }

    config_.LoadConfigfile(config_file.c_str());
}

RpcApplication& RpcApplication::instance() {
    static RpcApplication App;
    return App;
}

RpcConfig& RpcApplication::GetRpcConfig() {
    return config_;
}