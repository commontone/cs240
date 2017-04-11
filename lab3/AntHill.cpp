#include "AntHill.h"
#include <iostream>
#include <cstdlib>

using namespace std;

AntHill::AntHill(){
	this->current_ants = this->next_id = 0;
	ants = NULL;
}

AntHill::~AntHill(){
	int i;
	for(i = 0; i < current_ants; i++) {
		delete ants[i];
	}
	delete [] ants;
}

int AntHill::addAnt(){
	int i;
	Ant ** nants = new Ant*[current_ants+1];
	for(i = 0; i < current_ants; i++) {
		nants[i]=ants[i];
		
	}
	Ant * nant = new Ant(this->next_id);
	next_id++;
	//cerr << "Next ID: " << next_id << endl;
	nants[current_ants] = nant;
	current_ants++;
	delete [] ants;
	ants = nants;
	return next_id-1;
}

bool AntHill::removeAnt(int rid) {
	int i;
	int offset = 0;
	int si = -1;
	Ant ** nants = new Ant*[current_ants-1];
	for(i = 0; i < current_ants; i++) {
		if(ants[i]->getID() == rid) {
			si = i;
		}
	}
	if(si == -1) {
		
		delete [] nants;
		return false;
	}
	for(i = 0; i < current_ants - 1; i++) {
		if(i == si) {
			offset = 1;
		}
		nants[i] = ants[i+offset];
	}
	delete ants[si];
	current_ants = current_ants -1;
	delete [] ants;
	ants = NULL;
	ants = nants;
	return true;
}

Ant * AntHill::getAnt(int id) {
	int i;
	for(i = 0; i < current_ants; i++) {
		if(ants[i]->getID() == id) {
			return ants[i];
		}
	}
	return NULL;
}

void AntHill::move(){
	for(int i = 0; i < this->current_ants; i++){
		ants[i]->move();
	}
}

void AntHill::printHillInfo(){
	for(int i = 0; i < this->current_ants; i++){
		//cout << "Ant #" << ants[i]->getID() << " [" << ants[i]->getX() << "," << ants[i]->getY() << "]" << endl;
	}
}
