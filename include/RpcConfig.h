#pragma once

#include <unordered_map>
#include <string>

class RpcConfig {
    public:
        void LoadConfigfile(const char *config_file);
        std::string Load(const std::string &key);
    private:
        std::unordered_map<std::string, std::string> configMap_;
        void Trim(std::string &src);
};