#include "MDPThread.h"

#include <ctime>

MDPThread::MDPThread() : running(false) {}

void MDPThread::stop() {
    running.store(false, std::memory_order_release);
    
    if(runningThread.joinable())
        runningThread.join();
}

bool MDPThread::isRunning() const {
    return running.load(std::memory_order_acquire) && runningThread.joinable();
}

MDPThread::~MDPThread() {
    if(running.load(std::memory_order_acquire)) {
        stop();
    };	
}
