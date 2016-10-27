#include <queue>
#include "BinaryTree.h"

using namespace std;

int BinaryTree::height() const { 
	return(root==NULL)? 0 : root->height(root); 
}

int BinaryTree::size() { 
	return(root==NULL)? 0 : root->size(root); 
}

bool BinaryTree::isEmpty() const { 
	return root==NULL; 
}

double BinaryTree::average(BinaryNode *node,int *cost) {
	*cost+=node->Cost();
	if(node->right!=NULL)
		average(node->right,cost);
	if(node->left!=NULL)
		average(node->left,cost);
	return ((double)(*cost))/((double)(size()));
}

void BinaryTree::merge(int item,BinaryTree& t1,BinaryTree& t2) {
	if(t1.root==t2.root && t1.root!=NULL) {
		cerr << "Right tree and left tree are equal." << endl;
		return;
	}

	if(this!=&t1 && this!=&t2) 
		deleteTree(root);

	root = new BinaryNode(item,1,t1.root,t2.root);

	if(this!=&t1) t1.root = NULL;
	if(this!=&t2) t2.root = NULL;
}

void BinaryTree::deleteTree(BinaryNode *root) {
	if(root==NULL) 
		return;
	if(root->right!=NULL)
		deleteTree(root->right);
	if(root->left!=NULL)
		deleteTree(root->left);
	delete root;
}

BinaryNode *BinaryTree::findMin(BinaryNode *t) throw(empty) {
	if(t==NULL)
		throw empty();
	while(t->left != NULL) 
		t = t->left;
	return t;
}

BinaryNode *BinaryTree::removeMin(BinaryNode *t) throw(notFound) {
	if(t==NULL) 
		throw notFound();
	if(t->left!=NULL)
		t->left = removeMin(t->left);
	else {
		BinaryNode *node = t;
		t = t->right;
		delete node;
	}
	return t;
}

void insertRecursive(BinaryNode *node,int k,int compare) {
	++compare;
	if(k < node->Key()) {
		if(node->left==NULL)
			node->left = new BinaryNode(k,compare);
		else
			insertRecursive(node->left,k,compare);
	}
	else {
		if(node->right==NULL)
			node->right = new BinaryNode(k,compare);
		else
			insertRecursive(node->right,k,compare);
	}
}

void BinaryTree::insertNode(int k) {
	BinaryNode *node = root;
	if (root==NULL)
		root = new BinaryNode(k);
	else
		insertRecursive(root,k,1);
}

BinaryNode *BinaryTree::removeNode(int k,BinaryNode *t) throw(notFound) {
	if(t==NULL)
		throw notFound();
	if(k < t->key)
		t->left = removeNode(k,t->left);
	else if(k > t->key)
		t->right = removeNode(k,t->right);
	else if(t->left!=NULL && t->right!=NULL) {
		t->key = findMin(t->right)->key;
		t->right = removeMin(t->right);
	} 
	else {
		BinaryNode *node = t;
		t = (t->left!=NULL) ? t->left : t->right;
		delete node;
	}
	return t;
}

ostream& operator<<(ostream& os,const BinaryTree& tree) {
	int curLevel = 1;
	int nextLevel = 0;
	int curHeight = -1;

	if(tree.isEmpty()) 
		return os;

	queue<BinaryNode*> q;
	q.push(tree.getRoot());

	while(!q.empty()) {
		BinaryNode *node = q.front();
		q.pop();
		--curLevel;

		if(node!=NULL) {
			os << node->Key() << "[" << node->Cost() << "]";
			q.push(node->Left());
			q.push(node->Right());
			nextLevel+=2;
		}
		else if(curHeight != tree.height())
			os << "X ";
		if(curLevel==0) {
			os << endl;
			curLevel = nextLevel;
			nextLevel = 0;
			++curHeight;
		}
	}
	return os;
}