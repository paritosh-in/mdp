#include "MarketDataStore.h"

void MarketDataStore::put(const MarketData& md) {
	auto it = mdsMap.find(md.getSymbol());

	if (it != mdsMap.end()) {
		mtx.lock();

		*(it->second) = md;

		mtx.unlock();
		return;
	}

	mtx.lock();

	mdsList.push_back(md);
	mdsMap[md.getSymbol()] = std::prev(mdsList.end());

	mtx.unlock();
}

MarketData MarketDataStore::get(int symbol) const {
	auto it = mdsMap.find(symbol);
	
	if(it != mdsMap.end()) {
		return *(it->second);
	}

	return MarketData(-1, 0, 0);
}

std::list<MarketData> MarketDataStore::getFirst(size_t n) const {
	std::list<MarketData> firstN(mdsList.begin(), std::next(mdsList.begin(), std::min(n, mdsList.size())));

	return firstN;
}

void MarketDataStore::moveToLast(int symbol) {
	auto it = mdsMap.find(symbol);

	if(it == mdsMap.end())
		return;

	mtx.lock();

	mdsList.push_back(*(it->second));
	
	mdsList.erase(it->second);
	mdsMap.erase(it);

	mdsMap[symbol] = std::prev(mdsList.end());
	
	mtx.unlock();
}
