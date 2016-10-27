#include "BinaryNode.h"

using namespace std;

int BinaryNode::Key() { 
	return key; 
}

int BinaryNode::Cost() { 
	return cost; 
}
int BinaryNode::height(BinaryNode *t) {
	if(t==NULL)
		return -1;
	else {
		int rightHeight = height(t->right);
		int leftHeight = height(t->left);	
		return (leftHeight>rightHeight)? 1+leftHeight : 1+rightHeight;
	}
}

int BinaryNode::size(BinaryNode *t) {
	if(t==NULL)
		return 0;
	else
		return 1+size(t->left)+size(t->right);
}
