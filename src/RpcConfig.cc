#include "RpcConfig.h"

#include <iostream>

void RpcConfig::LoadConfigfile(const char *config_file) {
    FILE *fp = fopen(config_file, "r");
    fseek(fp, 0, 0);
    if (fp == nullptr) {
        std::cout << "configfile not exist" << std::endl;
        exit(EXIT_FAILURE);
    }

    while (!feof(fp)) {

        char buf[512] = {0};
        fgets(buf, sizeof(buf), fp);

        std::string src(buf);
        Trim(src);
        if (src[0] == '#' || src.empty()) continue;

        int idx = src.find('=');
        if (idx == -1) continue;

        std::string key, value;
        key = src.substr(0, idx);
        value = src.substr(idx + 1, src.size() - idx);
        Trim(key);
        Trim(value);
        if (value.back() == '\n')   value.pop_back();

        configMap_.insert({key, value});
    }
}

std::string RpcConfig::Load(const std::string &key) {
    auto it = configMap_.find(key);
    if (it == configMap_.end())
        return "";

    return configMap_[key];
}

void RpcConfig::Trim(std::string &src) {
    int idx = src.find_first_not_of(' ');
    if (idx != -1) {
        src = src.substr(idx, src.size() - idx);
    }
    idx = src.find_last_not_of(' ');
    if (idx != -1) {
        src = src.substr(0, idx + 1);
    }
}