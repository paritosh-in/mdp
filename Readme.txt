1. Use "run.sh" for compiling and running test case.


2. This runs testcase for N=100.
3. Other parameters are set in Application.cpp

Implementation:
	MarketDataPublihser usage Map and List for ordering of latest market data, and these implementation are in 
	MarketDataPublisher.cpp and MarketDataStore.cpp.

	For synchronization issues a mutex on all write operation in MarketDataStore.

	MarketDataPublisher usage Broadcaster(Broadcaster.cpp) to broadcast any price update.

	Main Application resides in Application.cpp, and runs two thread TimerThread(TimerThread.cpp) and PricingThread(PricingThread.cpp).
	PricingThread updates price and TimerThread triggers onTimer of MarketDataPublisher.


Limitations:
	Sync issues, as lock is on only write operations R-W conflict will remain. A better option will be using two locks
	one for read and another for write.
	
	In MarketDataStore.cpp all operations are using Call by Value, using shared_ptr will be better option it will reduce memry usage and many copy operations.
