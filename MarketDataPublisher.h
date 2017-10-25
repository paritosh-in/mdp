#ifndef __MARKETDATAPUBLISHER__H__
#define __MARKETDATAPUBLISHER__H__

#include "Broadcaster.h"
#include "MarketData.h"
#include "MarketDataStore.h"

#include <cstdint>

class MarketDataPublisher {
	public:
		void updatePrice(int symbolId, double price, uint64_t secondSinceEpoch);
		void onTimer(uint64_t secondSinceEpoch);

		MarketDataPublisher(Broadcaster &broadcaster, int maxIntervalSeconds, int maxPriceMove, int maxSymbolsAtTime);

	private:
		Broadcaster broadcaster;
		int maxIntervalSeconds;
		int maxPriceMove;
		int maxSymbolsAtTime;

		MarketDataStore mdStore;

		void publish(MarketData md, uint64_t currentTime);
};

#endif
