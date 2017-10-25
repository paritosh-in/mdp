#include "MarketData.h"

MarketData::MarketData(int symbol, double price, uint64_t updatedTime) {
	this->symbol = symbol;
	this->price = price;
	this->lastUpdatedTime = updatedTime;
}

/*MarketData::MarketData(const MarketData& md) {
	this->symbol = md.symbol;
	this->price = md.price;
	this->lastPublishedPrice = md.lastPublishedPrice;
	this->lastUpdatedTime = md.lastUpdatedTime;
	this->lastPublishedTime = md.lastPublishedTime;
}

MarketData& MarketData::operator=(const MarketData& md) {
}*/

int MarketData::getSymbol() const {
	return this->symbol;
}

double MarketData::getPrice() const {
	return this->price;
}

double MarketData::getLastPublishedPrice() const {
	return this->lastPublishedPrice;
}

uint64_t MarketData::getLastUpdatedTime() const {
	return this->lastUpdatedTime;
}

uint64_t MarketData::getLastPublishedTime() const {
	return this->lastPublishedTime;
}

void MarketData::setSybmol(const int symbol) {
	this->symbol = symbol;
}

void MarketData::setPrice(const double price) {
	this->price = price;
}

void MarketData::setLastPublishedPrice(const double lastPublishedPrice) {
	this->lastPublishedPrice = lastPublishedPrice;
}

void MarketData::setLastPublishedTime(const uint64_t lastPublishedTime) {
	this->lastPublishedTime = lastPublishedTime;
}

void MarketData::setLastUpdateTime(const uint64_t lastUpdateTime) {
	this->lastUpdatedTime = lastUpdateTime;
}
