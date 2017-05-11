#include <cstdlib>
#include <string>
#include <iostream>
#include <list>
#include "Map.h"
#include "City.h"
using namespace std;

City::City(std::string namea, int xa, int ya) {
	name = namea; //City Name
	x = xa; //X Position
	y = ya; //Y Position
	explored = false; //Adjacents have been explored
	dist = 0; //Distance from destination
	op = NULL; //Optimal Previous
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