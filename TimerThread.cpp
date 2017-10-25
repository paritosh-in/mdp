#include "TimerThread.h"

#include <ctime>

TimerThread::TimerThread() {}

void TimerThread::start(uint64_t timeout, std::function<void(uint64_t)> onTimeout) {
    if(running.load(std::memory_order_acquire))
        stop();

    running.store(true, std::memory_order_release);

    runningThread =  std::thread([this, timeout, onTimeout]() {
        while (running) {
            onTimeout(std::time(nullptr));                 
            std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
        }
    });
}

TimerThread::~TimerThread() {}
