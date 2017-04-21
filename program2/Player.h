#ifndef PLAYER_H
#define PLAYER_H

class Player {
	private:
	public:
		Card hand;
		Player(String, int);
		string getName();
		int getBudget();
		bool bet(int);
		void collectWinnings(int);
	
}

#endif