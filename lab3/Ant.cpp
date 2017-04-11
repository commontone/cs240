#include "AntHill.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Ant::Ant(int id) {
	this->id = id;
	x = y = 0;
}

void Ant::move(){
	int val = (rand() % 3) - 1;
	//cout << "val: "<< val << " [" << this->x << "," << this->y <<"]" <<endl;
	if(rand()%2){
		x += val;
	}else{
		y += val;
	}
	//cout << "[" << this->x << "," << this->y <<"]" <<endl;
}

Ant * Ant::operator=(Ant * other){
	this->id = other->getID();
	this->x = other->getX();
	this->y = other->getY();
	//cerr << this->id << " " << other->getID() << endl;
	return this;
}