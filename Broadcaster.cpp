#include "Broadcaster.h"

#include <iostream>

void Broadcaster::broadcast(int symbolId, double price) {
#if DEBUG
	std::cout << "Broadcaster::broadcast()" << std::endl;
	std::cout << symbolId << " | " << price << std::endl;
#endif

	std::cout << symbolId << " " << price << std::endl;
}
