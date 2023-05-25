#include "Logger.h"

#include <time.h>
#include <stdio.h>

#include <iostream>
#include <thread>

Logger::Logger() {
    std::thread logThread([&]() {
        while (true) {
            time_t now = time(nullptr);
            tm *nowTm = localtime(&now);
            std::vector<char>  file(128);
            snprintf(&*file.begin(), file.size(), "%d-%d-%d-log.txt",  
            nowTm->tm_year + 1900, nowTm->tm_mon + 1, nowTm->tm_mday);

            FILE *fp = fopen(&*file.begin(), "a+");
            if (fp == nullptr) {
                printf("%s:%d\n", __FILE__, __LINE__);
                exit(EXIT_FAILURE);
            }
            
            std::string msg = lockQueue_.pop();
            char bufTime[128] = {0};
            snprintf(bufTime, sizeof(bufTime), "%d:%d:%d => ", nowTm->tm_hour, nowTm->tm_min, nowTm->tm_sec);
            msg.insert(0, bufTime);
            msg.append("\n");
            fputs(msg.c_str(), fp);
            ::fclose(fp);
        }
    });

    logThread.detach();
}

Logger& Logger::instance() {
    static Logger logger;
    return logger;
}


void Logger::SetLogLevel(LogLevel level) {
    logLevel_ = level;
}

void Logger::Log(std::string msg) {
    std::cout << msg;
    lockQueue_.push(msg);
}