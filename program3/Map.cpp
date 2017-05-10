#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include "Map.h"
#include "City.h"
using namespace std;

//Read in a file and structure a map
Map::Map(string filename) {
	vector<City> cities;
	std::fstream fptr;
	fptr.open(filename, fstream::in);
	int line_counter = 0;
	while(!fptr.eof()) {
		string word;
		int a;
		int b;
		fptr>>word;
		fptr>>a;
		fptr>>b;
		cities.push_back(City(word,a,b));
		line_counter++;
	}
	vector<City>::iterator it = cities.begin();
	for(auto i:cities) {
		cout << i.getName() << " " << i.getXCoor() << " " << i.getYCoor() << " " << endl;
	}
	//cout << (*it).getXCoor() << endl;
	fptr.close();
	
	
}

//Return a City pointer corresponding to a given city name
City* Map::findByName(std::string cityName) {
	return (City*)0;
}

int main(int argc, char *argv[]) {
	cout << "Hello" << endl;
	Map map("townlist2.txt");
	return 0;
}