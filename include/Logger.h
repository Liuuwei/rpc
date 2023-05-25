#pragma once

#include "LockQueue.h"

#include <string>

enum LogLevel {
    INFO,
    ERROR,
};

class Logger {
    public:
        static Logger& instance();
        void SetLogLevel(LogLevel level);
        void Log(std::string msg);
    private:
        int logLevel_;
        LockQueue<std::string> lockQueue_;
        Logger();
        Logger(const Logger&) = delete;
        Logger(Logger&&) = delete;
};

#define LOG_INFO(logmsgformat, ...) \
    do { \
        Logger &logger = Logger::instance(); \
        logger.SetLogLevel(INFO); \
        char buf[1024] = {0}; \
        snprintf(buf, sizeof(buf), logmsgformat, ##__VA_ARGS__); \
        logger.Log(buf); \
    } while(0); 

#define LOG_ERROR(logmsgformat, ...) \
    do { \
        Logger &logger = Logger::instance(); \
        logger.SetLogLevel(ERROR); \
        char buf[1024] = {0}; \
        snprintf(buf, sizeof(buf), logmsgformat, ##__VA_ARGS__); \
        logger.Log(buf); \
    } while(0);