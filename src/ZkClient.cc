#include "ZkClient.h"

#include "RpcApplication.h"

#include <stdio.h>

ZkClient::ZkClient() : zhandle_(nullptr) {

}

ZkClient::~ZkClient() {
    if (zhandle_) 
        zookeeper_close(zhandle_);
}

void global_watch(zhandle_t *zh, int type, int state, const char *path, void *waterCtx) {
    if (type == ZOO_SESSION_EVENT) {
        if (state == ZOO_CONNECTED_STATE) {
            sem_t *sem = (sem_t *)zoo_get_context(zh);
            sem_post(sem);
        }
    }
}

/**
 * * 三线程
 * * api调用线程
 * * 网络线程
 * * watcher回调线程
*/

void ZkClient::Start() {
    std::string ip = RpcApplication::instance().GetRpcConfig().Load("zookeeperip");
    std::string port = RpcApplication::instance().GetRpcConfig().Load("zookeeperport");
    std::string host = ip + ":" + port;

    zhandle_ = zookeeper_init(host.c_str(), global_watch, 30000, nullptr, nullptr, 0);
    if(zhandle_ == nullptr) {
        printf("%s:%d\n", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    sem_t sem;
    sem_init(&sem, 0, 0);
    zoo_set_context(zhandle_, &sem);

    sem_wait(&sem);
    printf("zookeeper init success\n");
}

void ZkClient::Create(const char *path, const char *data, int datalen, int state) {
    char buf[128] = {0};
    int bufLen = sizeof(buf);
    int flag = 0;
    flag = zoo_exists(zhandle_, path, 0, nullptr);
    if (flag == ZNONODE) {
        flag = zoo_create(zhandle_, path, data, datalen, &ZOO_OPEN_ACL_UNSAFE, state, buf, bufLen);
        if (flag == ZOK) {
            printf("path create success path is %s value is %s\n", path, data);
        } else {
            printf("%s:%d\n", __FILE__, __LINE__);
            exit(EXIT_FAILURE);
        }
    }
}


std::string ZkClient::GetData(const char *path) {
    char buf[128] = {0};
    int bufLen = sizeof(buf);
    int flag = zoo_get(zhandle_, path, 0, buf, &bufLen, nullptr);

    if (flag != ZOK) {
        printf("%s:%d\n", __FILE__, __LINE__);
        return "";
    }
    return buf;
}