#ifndef BSTREE_H
#define BSTREE_H
#include <vector>
#include <cstdlib>
class BSTree {
	private:
		class Node{
			public:
				Node * left;
				Node * right;
				Node * parent;
				int value;
				Node(int);
				~Node();
		};
		Node * head;
		Node * current;
		Node * findNode(int);
	public:
		void removeleaf(int);
		void shortcircuit(int);
		void promotion(int);
		void listAddTraverse(Node *,std::vector<int>&);
		void deepCopyTraverse(Node *);
		void breadthTraverse(Node *,std::vector<int>&,int);
		void printTree();
		void printTreeGo(Node *,int);
		void print2DUtil(Node *, int, int);
		void clear();
		
		void sortedArray(std::vector<int>&);
		void heapArray(std::vector<int>&);
		bool remove(int);
		BSTree();
		BSTree(const BSTree&);
		bool empty();
		bool insert(int);
		bool find(int);
		~BSTree();
};

#endif