#ifndef __PRICINGTHREAD__H_
#define __PRICINGTHREAD__H_


#include "MDPThread.h"

class PricingThread : public MDPThread {
	public:
		void start(uint64_t interval, bool random, std::function<void(int, double, uint64_t)> onPriceUpdate);

	private:
		std::pair<int, double> getNextRandomQuote();
		std::pair<int, double> getNextInputQuote();
};

#endif
