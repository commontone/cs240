#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include "Map.h"
#include "City.h"
#define TEST 1
using namespace std;

//Read in a file and structure a maptemp
Map::Map(string filename) {
	//FILE READIING
	std::fstream fptr; //Create a file pointer
	fptr.open(filename, fstream::in); //Open the file
	while(!fptr.eof()) { //Go through the file, adding cities to the vector
		string word; //City Name
		int a; //X Coord
		int b; //Y Coord
		fptr>>word;
		fptr>>a;
		fptr>>b;
		City* temp = new City(word,a,b);
		cities.push_back(temp);
	}
	fptr.close();
	
	//ADJACENCY LIST
	//List of cities
	
	//0,0 IS THE TOP LEFT/NORTHWEST OF THE GRAPH
	for(auto i:cities) {
		//There can only be 4 adjacent cities, given by the rules of adjacency
		//So, let there be a North, South, East, and West city
		City *north = NULL, *south = NULL, *east = NULL, *west = NULL;
		for(auto j:cities) {
			if(i==j) {
				//It's the same, do nothing.
			}
			else if(j->getXCoor() == i->getXCoor() && j->getYCoor() < i->getYCoor()) {
				if(north==NULL) {
					north = j;
				} else if(north->getYCoor() < j->getYCoor()) {
					north = j;
				}
				
			} else if(j->getXCoor() == i->getXCoor() && j->getYCoor() > i->getYCoor()) {
				if(south==NULL) {
					south = j;
				} else if(south->getYCoor() > j->getYCoor()) {
					south = j;
				}
			} else if(j->getYCoor() == i->getYCoor() && j->getXCoor() < i->getXCoor()) {
				if(west==NULL) {
					west = j;
				} else if(west->getXCoor() < j->getXCoor()) {
					west = j;
				}
			} else if(j->getYCoor() == i->getYCoor() && j->getXCoor() > i->getXCoor()) {
				if(east==NULL) {
					east = j;
				} else if(east->getXCoor() > j->getXCoor()) {
					east = j;
				}
			}
		}
		//PRINT STATEMENT. REMOVE LATER.
		cout << i->getName() << " " << i->getXCoor() << " " << i->getYCoor() << " " << endl;
		//Now add all the possible adjacencies. Null cities will be ignored.
		i->addAdj(north);
		i->addAdj(south);
		i->addAdj(east);
		i->addAdj(west);
		
	}
	
	cout << cities[0]->getAdjacent().front()->getName() << endl;
	
	/*
	for(auto i:cities) {
		cout << i->getName() << " " << i->getXCoor() << " " << i->getYCoor() << " " << endl;
	}*/
	//cout << (*it).getXCoor() << endl;
	
	
	
}

Map::~Map() {
	for(int i = 0; i< cities.size(); i++) {
		delete cities[i];
	}
	cities.clear();
}

vector<City*> Map::shortestPath(City* start, City* dest) {
	vector<City*> ans;
	ans.push_back(start);
	int i = 0;
	//Reset all necessary values
	for(i = 0; i< cities.size(); i++) {
		cities[i]->explored = false;
		cities[i]->dist = -1;
		cities[i]->op = NULL;
	}
	start->dist = 0; //Make the start a distance of 0
	//Get the path distance to the start from each point
	for(i = 0; i< cities.size(); i++) {
		City* now = nextTarget();
		for(auto t:now->getAdjacent()) {
			if(t->dist==-1) {
				t->dist = pathDistance(now,t);
				t->op = now;
			}
		}
		now->explored = true;
	}
	
	return ans;
}

City* Map::nextTarget() {
	City* ret = NULL;
	int i = 0;
	//Find the first unexplored city
	for(i = 0; i< cities.size(); i++) {
		if(cities[i]->explored==false) {
			ret = cities[i];
			break;
		}
	}
	//Now find the lowest distance city
	for(i = 0; i< cities.size(); i++) {
		if(cities[i]->explored==false && cities[i]->dist!=-1 && cities[i]->dist < ret->dist) {
			ret = cities[i];
		}
	}
	return ret;
}

unsigned int Map::pathDistance(City* start, City* dest) {
	unsigned int ret = 0;
	ret = abs(start->getXCoor()-dest->getXCoor()) 
			+ abs(start->getYCoor()-dest->getYCoor()) 
			+ start->dist;
	return ret;
}

//Return a City pointer corresponding to a given city name
City* Map::findByName(std::string cityName) {
	City* t = NULL;

	for(auto t:cities) {
		if(t->getName()==cityName) {
			return t;
		}
	}
	return t;
}
#if TEST
int main(int argc, char *argv[]) {
	cout << "Hello" << endl;
	Map map("townlist2.txt");
	City* how = map.findByName("asgard");
	cout << map.pathDistance(map.findByName("doomstadt"), map.findByName("kun-lun")) << endl;
	return 0;
}
#endif