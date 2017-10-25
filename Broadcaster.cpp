#include "Broadcaster.h"

#include <iostream>

void Broadcaster::broadcast(int symbolId, double price) {
	std::cout << "Broadcaster::broadcast()" << std::endl;
	std::cout << symbolId << " | " << price << std::endl;
}
