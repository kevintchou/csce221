#include <iostream>
#include <fstream>
#include <string>
#include "BinaryTree.h"

using namespace std;

int main() {
	string file;
	cout << "File name: ";
	cin >> file;
	ifstream is(file.c_str(), ifstream::in);
	
	int k;
	cout << "Input data: " << endl;
	is >> k;
	cout << k << endl;
	BinaryTree tree(k);
	while(is.good()) {
		is >> k;
		if(is.good()) {
			cout << k << endl;
			tree.insertNode(k);
		}
	}
	cout << endl;

	int* search = new int(0);
	if(tree.size()<16)
		cout << "Binary tree: " << endl << tree;

	cout << "Number of nodes: " << tree.size() << endl;
	cout << "Average search cost: " << tree.average(tree.getRoot(),search) << endl << endl;
	
	cout << "Please enter the key to remove: ";
	cin >> k;
	tree.removeNode(k,tree.getRoot());
	
	*search = 0;
	if(tree.size()<16)
		cout << endl << "Binary tree after element removed: " << endl << tree;

	cout << "Number of nodes: " << tree.size() << endl;
	cout << "Average search cost is " << tree.average(tree.getRoot(),search) << endl;
	
	delete search;
}