#ifndef MAP_H
#define MAP_H
#include <list>
#include <cstdlib>
#include <string>
#include <vector>
#include "City.h"

class Map {
	public:
		Map(std::string);
		City* findByName(std::string);
		std::vector<City*> shortestPath(City*, City*);
		unsigned int pathDistance(City*,City*);
		
		~Map();
	private:
		std::vector<City*> cities;
		std::list<City*> adj;
		City* nextTarget();
};

#endif