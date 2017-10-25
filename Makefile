CXXFLAGS += -std=c++11 -Wall -g

CC = g++ 

all: Application

Application: TimerThread.o Application.o MarketDataPublisher.o PricingThread.o MDPThread.o Broadcaster.o MarketData.o MarketDataStore.o
	$(CC) $(CXXFLAGS) TimerThread.o Application.o MarketDataPublisher.o MDPThread.o PricingThread.o Broadcaster.o MarketData.o MarketDataStore.o -o Application -lpthread -lm

Application.o: Application.cpp TimerThread.h MarketDataPublisher.h MDPThread.h Broadcaster.h
	$(CC) $(CXXFLAGS) -c Application.cpp

MarketDataPublisher.o: MarketDataPublisher.cpp MarketDataPublisher.h Broadcaster.h MarketData.h MarketDataStore.h
	$(CC) $(CXXFLAGS) -c MarketDataPublisher.cpp

TimerThread.o: TimerThread.cpp TimerThread.h MDPThread.h
	$(CC) $(CXXFLAGS) -c TimerThread.cpp

MDPThread.o: MDPThread.cpp MDPThread.h
	$(CC) $(CXXFLAGS) -c MDPThread.cpp 

PricingThread.o: PricingThread.cpp PricingThread.h MDPThread.h
	$(CC) $(CXXFLAGS) -c PricingThread.cpp

Broadcaster.o: Broadcaster.cpp Broadcaster.h
	$(CC) $(CXXFLAGS) -c Broadcaster.cpp

MarketData.o: MarketData.cpp MarketData.h
	$(CC) $(CXXFLAGS) -c MarketData.cpp

MarketDataStore.o: MarketDataStore.cpp MarketDataStore.h
	$(CC) $(CXXFLAGS) -c MarketDataStore.cpp

clean :
	rm MDPThread.o TimerThread.o MarketDataPublisher.o Application.o Broadcaster.o MarketData.o MarketDataStore.o Application
