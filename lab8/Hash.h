#ifndef HASH_H
#define HASH_H

public class Hash {
	public:
		Hash(unsigned int);
		bool insert(string, string);
		bool remove(string);
		string find(string);
		bool empty();
		bool size();
		void printHash();
		int hasher(string);
	private:
}

#endif