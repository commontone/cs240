#ifndef CITY_H
#define CITY_H
#include <list>
#include <cstdlib>
#include <string>

class City {
	public:
		City(std::string, int, int);
		std::string getName();
		int getXCoor();
		int getYCoor();
		std::list<City*> getAdjacent();
		bool operator<(City &c);
	private:
		std::string name;
		int x;
		int y;
};

#endif