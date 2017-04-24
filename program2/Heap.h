#ifndef HEAP_H
#define HEAP_H

class Heap {
	public:
		Heap();
		Heap(string);
		Heap(const Heap&);
		void addPlayer(Player);
		Player getPlayer();
		vector<Player> getArray();
		bool empty();
		unsigned int size();
	private:
}

#endif