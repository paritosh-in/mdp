#ifndef __MARKETDATA__H_
#define __MARKETDATA__H_

#include <cstdint>

class MarketData {
	private:
		int symbol;
		double price;
		double lastPublishedPrice;
		uint64_t lastUpdatedTime;
		uint64_t lastPublishedTime;

	public:
		int getSymbol() const;
		double getPrice() const;
		double getLastPublishedPrice() const;
		uint64_t getLastUpdatedTime() const;
		uint64_t getLastPublishedTime() const;

		void setSybmol(const int symbol);
		void setPrice(const double price);
		void setLastPublishedPrice(const double lastPublishedPrice);
		void setLastPublishedTime(const uint64_t lastPublishedTime);
		void setLastUpdateTime(const uint64_t lastUpdateTime);

		MarketData(int symbol, double price, uint64_t lastUpdatedPrice);

		// MarketData(const MarketData& md);

		// MarketData& operator=(const MarketData& md);
};

#endif
