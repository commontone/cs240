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
	explored = false;
}

std::string City::getName() {
	return name;
}

City::~City() {
}

void City::addAdj(City* add) {
	if(add!=NULL) {
		adj.push_back(add);
	}
}

list<City*> City::getAdjacent() {
	return adj;
}

int City::getXCoor() {
	return x;
}

int City::getYCoor() {
	return y;
}