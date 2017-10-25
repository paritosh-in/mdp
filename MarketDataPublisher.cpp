#include "MarketDataPublisher.h"

#include <algorithm>
#include <iostream>
#include <list>

MarketDataPublisher::MarketDataPublisher(Broadcaster& broadcaster,
										 int maxIntervalSeconds,
										 int maxPriceMove,
										 int maxSymbolsAtTime) {
	this->broadcaster = broadcaster;
	this->maxIntervalSeconds = maxIntervalSeconds;
	this->maxPriceMove = maxPriceMove;
	this->maxSymbolsAtTime = maxSymbolsAtTime;
}

void MarketDataPublisher::updatePrice(int symbolId, double price, uint64_t secondSinceEpoch) {
#if DEBUG
	std::cout << "MarketDataPublisher::updatePrice()" << std::endl;
	std::cout << symbolId << " | " << price << " | " << secondSinceEpoch << std::endl;
#endif

	bool shouldPublish = false;

	MarketData md = mdStore.get(symbolId);
	if(md.getSymbol() != -1) {
		if(price >= md.getPrice() + maxPriceMove)
			shouldPublish = true;

		md.setPrice(price);
		md.setLastUpdateTime(secondSinceEpoch);
	} else {
		shouldPublish = true;
		md = MarketData(symbolId, price, secondSinceEpoch);
	}

	mdStore.put(md);

	if(shouldPublish)	
		publish(md, secondSinceEpoch);
}

void MarketDataPublisher::onTimer(uint64_t secondSinceEpoch) {
#if DEBUG
	std::cout << "MarketDataPublisher::onTimer()" << std::endl;
	std::cout << secondSinceEpoch << std::endl;
#endif
	std::list<MarketData> mdList = mdStore.getFirst(maxSymbolsAtTime);

	std::for_each(mdList.begin(), mdList.end(), [this, secondSinceEpoch](MarketData md) {
		// std::cout << md.getSymbol() << " | " << md.getLastPublishedTime() + maxIntervalSeconds << " | " << secondSinceEpoch << std::endl;
		if(secondSinceEpoch >= md.getLastPublishedTime() + maxIntervalSeconds)
			publish(md, secondSinceEpoch);
	});
}

void MarketDataPublisher::publish(MarketData md, uint64_t currentTime) {
	md.setLastPublishedTime(currentTime);
	md.setLastPublishedPrice(md.getPrice());

	broadcaster.broadcast(md.getSymbol(), md.getPrice());

	mdStore.put(md);

	mdStore.moveToLast(md.getSymbol());
}
