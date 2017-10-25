#ifndef __MARKETDATASTORE_H_
#define __MARKETDATASTORE_H_

#include "MarketData.h"

#include <list>
#include <mutex>
#include <unordered_map>

class MarketDataStore {
	private:
		// typedef typename std::pair<int, MarketData> MDPair;
		typedef typename std::list<MarketData>::iterator MDListIterator;
		
		std::list<MarketData> mdsList;
		std::unordered_map<int, MDListIterator> mdsMap;

		std::mutex mtx;

	public:
		void put(const MarketData& md);
		MarketData get(int symbol) const;
		std::list<MarketData> getFirst(size_t n) const;
		void moveToLast(int symbol);
};

#endif
