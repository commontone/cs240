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
	private:
		std::vector<City> cities;
};

#endif