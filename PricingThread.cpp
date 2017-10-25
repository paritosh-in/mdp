#include "PricingThread.h"

#include <fstream>
#include <random>

void PricingThread::start(uint64_t interval, bool random, std::function<void(int, double, uint64_t)> onUpdatePrice) {
    
	if(running.load(std::memory_order_acquire))
        stop();

    running.store(true, std::memory_order_release);

    runningThread =  std::thread([this, interval, random, onUpdatePrice]() {
        while (running) {
			std::pair<int, double> quote = random ? getNextRandomQuote() : getNextInputQuote();
            onUpdatePrice(quote.first, quote.second, std::time(nullptr));
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
        }
    });
}

std::pair<int, double> PricingThread::getNextRandomQuote() {
	std::random_device rd;
    std::mt19937 gen(rd());
	std::uniform_int_distribution<int> unii(1, N);
	std::uniform_real_distribution<double> unid(100.0, 200.0);
	// std::default_random_engine re;
	
	int symbolId = unii(gen);
	double price = unid(gen);

	return std::make_pair(symbolId, price);
}

std::pair<int, double> PricingThread::getNextInputQuote() {

	static std::ifstream prices("price.txt");

	int a;
	double b;

	if(prices >> a >> b)
		return std::make_pair(a, b);

	return getNextRandomQuote();

}
