#ifndef ___TIMER__H__
#define ___TIMER__H__

#include "MDPThread.h"

class TimerThread : public MDPThread {
	public:
        void start(uint64_t timeout, std::function<void(uint64_t)> onTimeout);
		TimerThread();
		~TimerThread();
};

#endif
