#include <iostream>
#include <unistd.h>

#include "TimerThread.h"
#include "PricingThread.h"
#include "MarketDataPublisher.h"

void callMe(uint64_t secondSinceEpoch) {
	std::cout << "You Seriously called Me @ " << secondSinceEpoch << std::endl;
}

int main() {
	TimerThread timerThread;
	PricingThread pricingThread;

	Broadcaster broadcaster;
	MarketDataPublisher mdp(broadcaster, 2, 10, 4);

	timerThread.start(1000, std::bind(&MarketDataPublisher::onTimer, &mdp, std::placeholders::_1));
	pricingThread.start(500, std::bind(&MarketDataPublisher::updatePrice, &mdp, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

	sleep(20);
	
	return 0;
}
