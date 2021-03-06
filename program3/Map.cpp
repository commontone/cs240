#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include "Map.h"
#include "City.h"
#define TEST 0
using namespace std;

//Read in a file and structure a map
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
	
	//ADJACENCY LISTS
	
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
		//Now add all the possible adjacencies. Null cities will be ignored.
		i->addAdj(north);
		i->addAdj(south);
		i->addAdj(east);
		i->addAdj(west);
		
	}
}

Map::~Map() {
	for(int i = 0; i< cities.size(); i++) {
		delete cities[i];
	}
	cities.clear();
}

vector<City*> Map::shortestPath(City* start, City* dest) {
	vector<City*> ans;
	int i = 0;
	//Reset all necessary values
	for(i = 0; i< cities.size(); i++) {
		cities[i]->explored = false;
		cities[i]->dist = -1;
		cities[i]->op = NULL;
	}
	dest->dist = 0; //Make the start a distance of 0
	dest->op = dest;
	//Get the path distance to the end from each point
	for(i = 0; i< cities.size(); i++) {
		City* now = nextTarget(); 
		for(auto t:now->getAdjacent()) {
			if(t->dist==-1) {
				t->dist = pathDistance2(now,t);
				t->op = now;
				
			} else { 
				
				if(pathDistance2(now,t) < t->dist) {
					t->dist = pathDistance2(now,t); 
					t->op = now;
				}
			}
		}
		now->explored = true;
	}
	

	std::vector<City*>::iterator it;
	it = ans.begin();
	//Evaluate the path, starting from the start
	if(start->dist != -1) {
		City* cur = start;
		ans.push_back(start);
		while(cur!=dest) { //Until the destination is reached, keep going to the optimal previous.
			cur = cur->op;
			ans.push_back(cur);
		}
	}
	
	return ans;
}

void Map::pStatus() {
	cout << "\n--VVVVVVVVVV----" << endl;
	int i = 0;
	for(i = 0; i< cities.size(); i++) {
		
		if(cities[i]->op!=NULL) {
			
			cout << cities[i]->getName() << "\t" << cities[i]->dist << "\t" << cities[i]->op->getName() << endl;
		} else {
			cout << cities[i]->getName() << "\t" << cities[i]->dist << "\tNULL" << endl;
		}
		
	}
	cout << "----------------\n" << endl;
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
		if(cities[i]->explored==false && cities[i]->dist!=-1) {
			ret = cities[i];
			//cout << "RET: " << cities[i]->getName() << endl;
		}
	}
	
	/*for(i = 0; i< cities.size(); i++) {
		if(cities[i]->explored==false && ret == NULL) {
			ret = cities[i];
		}
	}*/
	return ret;
}

unsigned int Map::pathDistance2(City* start, City* dest) {
	unsigned int ret = -1;
	if(start->dist==-1) {
		return ret;
	}
	
	ret = abs(start->getXCoor()-dest->getXCoor()) 
			+ abs(start->getYCoor()-dest->getYCoor()) 
			+ start->dist;
	return ret;
}

unsigned int Map::pathDistance(City* start, City* dest) {
	unsigned int ret = -1;
	std::vector<City*> hi = shortestPath(start,dest);
	if(hi.size()==0) {
		ret = -1;
		return ret;
	} else {
		return start->dist;
	}
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
	cout << map.shortestPath(map.findByName("attilan"), map.findByName("metropolis")).size() << endl;
	return 0;
}
#endif