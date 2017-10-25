#ifndef __PRICINGTHREAD__H_
#define __PRICINGTHREAD__H_

#ifndef N
#define N 100
#endif

#include "MDPThread.h"

class PricingThread : public MDPThread {
	public:
		void start(uint64_t interval, std::function<void(int, double, uint64_t)> onPriceUpdate);

	private:
		std::pair<int, double> getNextQuote();
};

#endif
