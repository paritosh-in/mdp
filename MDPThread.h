#ifndef __MDPTHREAD__H__
#define __MDPTHREAD__H__

#include <atomic>
#include <thread>

class MDPThread {
    protected:
        std::atomic<bool> running;
        std::thread runningThread;

    public:
        void stop();
		bool isRunning() const;

	MDPThread();
	~MDPThread();
};

#endif
