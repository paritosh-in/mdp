#include <iostream>
#include <unistd.h>

#include "TimerThread.h"
#include "PricingThread.h"
#include "MarketDataPublisher.h"

void runTest(int maxInterval, double maxPriceMove, int maxSymbolAtTime, int duration, int timerInterval, int priceUpdateInterval) {
	bool random = true;
	if(duration*1000 / priceUpdateInterval == 40)
		random = false;
	TimerThread timerThread;
	PricingThread pricingThread;

	Broadcaster broadcaster;
	MarketDataPublisher mdp(broadcaster, maxInterval, maxPriceMove, maxSymbolAtTime);

	timerThread.start(timerInterval, std::bind(&MarketDataPublisher::onTimer, &mdp, std::placeholders::_1));
	pricingThread.start(priceUpdateInterval, random, std::bind(&MarketDataPublisher::updatePrice, &mdp, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

	sleep(duration);

	timerThread.stop();
	pricingThread.stop();
}

int main() {
	runTest(2, 10, 4, 20, 1000, 500);

	return 0;
}
