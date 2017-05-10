#include <cstdlib>
#include <string>
#include <iostream>
#include <list>
#include "Map.h"
#include "City.h"
using namespace std;

City::City(std::string namea, int xa, int ya) {
	name = namea;
	x = xa;
	y = ya;
}

std::string City::getName() {
	return name;
}

int City::getXCoor() {
	return x;
}

int City::getYCoor() {
	return y;
}