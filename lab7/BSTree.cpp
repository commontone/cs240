#include "BSTree.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <iomanip>
#define COUNT 10
using namespace std;

BSTree::BSTree() {
	this->head = NULL;
	this->current = head;
}

BSTree::BSTree(const BSTree &old_tree) {
	this->head = NULL;
	this->current = head;
	deepCopyTraverse(old_tree.head);
}

BSTree::~BSTree() {
	clear();
	//cout << "Empty? " << empty() << endl;
}

void BSTree::sortedArray(std::vector<int> &list) {
	listAddTraverse(head,list);
}

void BSTree::heapArray(std::vector<int> &list) {
	breadthTraverse(head,list,0);
}


void BSTree::clear() {
	while(head!=NULL) {
		remove(head->value);
	}
}
BSTree::Node::Node(int val) {
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
	this->value = val;
}

BSTree::Node::~Node() {
}

void BSTree::listAddTraverse(Node * n, std::vector<int> &list) {
	if(n!=NULL) {
		listAddTraverse(n->left,list);
		list.push_back(n->value);
		listAddTraverse(n->right,list);
	}
}

void BSTree::breadthTraverse(Node * n, std::vector<int> &list, int level) {
	if(n!=NULL) {
		breadthTraverse(n->left,list,level+1);
		cout << "Level A: " << level << " Value: " << n->value << endl;
		breadthTraverse(n->right,list,level+1);
		//cout << "Level B: " << level << " Value: " << n->value << endl;
	}
}

void BSTree::deepCopyTraverse(Node * n) {
	if(n!=NULL) {
		insert(n->value);
		deepCopyTraverse(n->left);
		deepCopyTraverse(n->right);
	}
}


bool BSTree::remove(int val) {
	if(!find(val)) {
		//cout << "Value not found" << endl;
		return false;
	}
	Node * target = findNode(val);
	if(target->left==NULL && target->right==NULL) {
		removeleaf(val);
	} else if((target->left==NULL)^(target->right==NULL)) {
		shortcircuit(val);
	} else {
		promotion(val);
	}
	return true;
}

void BSTree::removeleaf(int val) {
	Node * target = findNode(val);
	if(target->value == head->value) {
		head = NULL;
	} else if(target->parent->left!=NULL && target==target->parent->left) {
		target->parent->left = NULL;
	} else if(target->parent->right!=NULL){
		target->parent->right = NULL;
	}
	delete target;
}

void BSTree::shortcircuit(int val) {
	Node * target = findNode(val);
	if(target==head) {
		if(target->left!=NULL) {
			head = head->left;
		} else {
			head = head->right;
		}
	} else if(target->parent->left!=NULL && target->value==target->parent->left->value) {
		//The target is a left child
		if(target->left!=NULL) {
			target->left->parent = target->parent;
			target->parent->left = target->left;
		} else {
			target->right->parent = target->parent;
			target->parent->left = target->right;
		}
		
	} else {
		//The target is a right child
		if(target->left!=NULL) {
			target->left->parent = target->parent;
			target->parent->right = target->left;
		} else {
			target->right->parent = target->parent;
			target->parent->right = target->right;
		}
	}
	delete target;
	
}

void BSTree::promotion(int val) {
	Node * target = findNode(val);
	Node * work = target;
	int temp = 0;
	temp = work->value;
	work = work->left;
	while(work->right!=NULL) {
		work = work->right;
	}
	/*if(work->left!=NULL) {
		work->left->parent = work->parent;
		if(work->parent->right!=NULL) {
			work->parent->right = work->left;
		} else {
			work->parent->left = work->left;
		}
	}*/
	temp=work->value;
	remove(work->value);
	target->value = temp;
	
}

bool BSTree::empty() {
	if(head==NULL) {
		return true;
	}
	return false;
}

bool BSTree::insert(int val) {
	if(find(val)) {
		return false;
	} else if(head==NULL) {
		head = new Node(val);
	} else {
		current = head;
		int going = 1;
		while(going) {
			if(val<current->value) {
				if(current->left==NULL) {
					current->left = new Node(val);
					current->left->parent = current;
					going = 0;
				} else {
					current = current->left;
				}
			} else {
				if(current->right==NULL) {
					current->right = new Node(val);
					current->right->parent = current;
					going = 0;
				} else {
					current = current->right;
				}
			}
		}
		
	}
	return false;
}

bool BSTree::find(int val) {
	if(head==NULL) {
		return false;
	} else {
		current = head;
		int going = 1;
		while(going) {
			if(val==current->value) {
				return true;
			} else if(val<current->value) {
				if(current->left==NULL) {
					return false;
					going = 0;
				} else {
					current = current->left;
				}
			} else {
				if(current->right==NULL) {
					return false;
					going = 0;
				} else {
					current = current->right;
				}
			}
		}
		
	}
	return false;
}

void BSTree::printTree() {
	print2DUtil(head,0,2);
}

void BSTree::printTreeGo(Node * p, int indent) {
	 if(p != NULL) {
        if(p->right) {
            printTreeGo(p->right, indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
        std::cout<< p->value << "\n ";
        if(p->left) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            printTreeGo(p->left, indent+4);
        }
    }
}

void BSTree::print2DUtil(Node * root, int space, int kind)
{
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->right, space, 0);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
	if(kind==1) {
		printf("\\%d\n", root->value);
	} else if (kind==0){
		printf("/%d\n", root->value);
	} else {
		printf(">%d\n", root->value);
	}
    print2DUtil(root->left, space, 1);
}


BSTree::Node * BSTree::findNode(int val) {
	if(head==NULL) {
		return NULL;
	} else {
		current = head;
		int going = 1;
		while(going) {
			if(val==current->value) {
				return current;
			} else if(val<current->value) {
				if(current->left==NULL) {
					cout << "Bad Node Value Requested" << endl;
					return NULL;
					going = 0;
				} else {
					current = current->left;
				}
			} else {
				if(current->right==NULL) {
					cout << "Bad Node Value Requested" << endl;
					return NULL;
					going = 0;
				} else {
					current = current->right;
				}
			}
		}
		
	}
	cout << "Something in findNode went really wrong. Woah." << endl;
	return NULL;
}
/*
int main() {
	BSTree tree;
	cout << "Testing for empty:" << endl;
	cout << tree.empty() << endl;
	cout << "Testing for 3, 5, and 7. First with none, then insert(5), insert(3), and insert(7):" << endl;
	cout << tree.find(3) << endl;
	cout << tree.find(5) << endl;
	cout << tree.find(7) << endl;
	cout << "Adding 5" << endl;
	tree.insert(5);
	cout << tree.find(3) << endl;
	cout << tree.find(5) << endl;
	cout << tree.find(7) << endl;
	cout << "Adding 3" << endl;
	tree.insert(3);
	cout << tree.find(3) << endl;
	cout << tree.find(5) << endl;
	cout << tree.find(7) << endl;
	cout << "Adding 7" << endl;
	tree.insert(7);
	cout << tree.find(3) << endl;
	cout << tree.find(5) << endl;
	cout << tree.find(7) << endl;
	tree.insert(9);
	tree.remove(7);
	tree.remove(9);
	tree.remove(3);
	tree.remove(5);
	cout << "Empty? " << tree.empty() << endl;
	
	tree.insert(10);
	tree.insert(15);
	tree.insert(5);
	
	tree.remove(15);
	cout << "5? " << tree.find(5) << endl;
	cout << "10? " << tree.find(10) << endl;
	cout << "15? " << tree.find(15) << endl;
	cout << "Empty? " << tree.empty() << endl;
	tree.remove(10);
	cout << "5? " << tree.find(5) << endl;
	cout << "10? " << tree.find(10) << endl;
	cout << "15? " << tree.find(15) << endl;
	cout << "Empty? " << tree.empty() << endl;
	cout << "5? " << tree.find(5) << endl;
	cout << "10? " << tree.find(10) << endl;
	cout << "15? " << tree.find(15) << endl;
	cout << "Empty? " << tree.empty() << endl;
	return 0;
}
*/

















