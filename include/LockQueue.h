#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>

template<typename T>
class LockQueue {
    public:
        void push(const T &data) {
            std::lock_guard lock(mutex_);
            queue_.push(data);
            cond_.notify_one();
        }
        T pop() {
            std::unique_lock lock(mutex_);
            while (queue_.empty()) {
                cond_.wait(lock);
            }
            T data = queue_.front();
            queue_.pop();
            return data;
        }
    private:
        std::queue<T> queue_;
        std::mutex mutex_;
        std::condition_variable cond_;
};