#ifndef ANT_H
#define ANT_H
#include "AntHill.h"

class Ant{
	private:
		int id;
		int x;
		int y;
	public:
		Ant(int);
		void move();
		int getID() {
			return this->id;
		}
		int getX() {
			return this->x;
		}
		int getY() {
			return this->y;
		}
		Ant * operator=(Ant*);
};
#endif
