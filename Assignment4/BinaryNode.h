#include <iostream>

using namespace std;

class BinaryNode {
	private:
		friend class BinaryTree;
		int key;
		int cost;
	public:
		BinaryNode *left,*right;
		BinaryNode(int k = 0,int search = 1,BinaryNode *lt = NULL,BinaryNode *rt = NULL) : key(k),cost(search),left(lt),right(rt) {}
		
		BinaryNode *Right() { 
			return right;
		}
		BinaryNode *Left() { 
			return left; 
		}
		int Key();
		int Cost();
		int height(BinaryNode *t);
		int size(BinaryNode *t);
		BinaryNode *copy();
};

