#ifndef CITY_H
#define CITY_H

#include <list>
#include <cstdlib>
#include <string>
#include "Map.h"

class City {
	public:
		City(std::string, int, int);
		std::string getName();
		int getXCoor();
		int getYCoor();
		void addAdj(City*); 
		std::list<City*> getAdjacent();
		bool operator<(City &c);
		
		bool explored; //Are this city's adjacents explored?
		int dist; //Total distance from destination
		City* op; //Optimal Previous City
		
		~City();
		
	private:
		std::list<City*> adj;
		std::string name;
		int x;
		int y;
		
		
};

#endif