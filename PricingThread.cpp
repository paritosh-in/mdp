#include "PricingThread.h"

#include <random>

void PricingThread::start(uint64_t interval, std::function<void(int, double, uint64_t)> onUpdatePrice) {
    if(running.load(std::memory_order_acquire))
        stop();

    running.store(true, std::memory_order_release);

    runningThread =  std::thread([this, interval, onUpdatePrice]() {
        while (running) {
			std::pair<int, double> quote = getNextQuote();
            onUpdatePrice(quote.first, quote.second, std::time(nullptr));
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
        }
    });
}

std::pair<int, double> PricingThread::getNextQuote() {
	std::random_device rd;
    std::mt19937 gen(rd());
	std::uniform_int_distribution<int> unii(1, N);
	std::uniform_real_distribution<double> unid(100.0, 200.0);
	// std::default_random_engine re;
	
	int symbolId = unii(gen);
	double price = unid(gen);

	return std::make_pair(symbolId, price);
}
