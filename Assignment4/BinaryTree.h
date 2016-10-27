#include <iostream>
#include "BinaryNode.h"

using namespace std;

class empty {};
class notFound {};

class BinaryTree {
	private:
		BinaryNode *root;
		void deleteTree(BinaryNode *root);
	public:
		BinaryTree() { 
			root = NULL; 
		}
		BinaryTree(int k) { 
			root = new BinaryNode(k); 
		}
		~BinaryTree() { 
			deleteTree(root); 
			root = NULL; 
		}
		BinaryNode *getRoot() const { 
			return root; 
		}

		void copy(BinaryTree& rhs) {
			if(this!=&rhs) {
				deleteTree(root);
				if(rhs.root!=NULL)
					root = rhs.root;
			}
		}

		int height() const;
		int size();
		bool isEmpty() const;
		double average(BinaryNode *root, int *cost);

		void merge(int item,BinaryTree& t1,BinaryTree& t2);
		BinaryNode* findMin(BinaryNode *t) throw(empty);
		BinaryNode* removeMin(BinaryNode *t) throw(notFound);
		void insertNode(int k);
		BinaryNode* removeNode(int k,BinaryNode *t) throw(notFound);
};

ostream& operator<<(ostream& os, const BinaryTree& tree);

