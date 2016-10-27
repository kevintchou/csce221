#pragma once

#include "TemplateDoublyLinkedList.h"
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Disjoint Set
template <typename T>
class DisjointSet {
private:
	vector<DListNode<T>*> nodeLocator;
public:
	~DisjointSet();
	DisjointSet(int n);
	vector<DListNode<T>*> getNodeLocator() const; 
	DListNode<T>* MakeSet(int key, T node);
	DListNode<T>* Union(DListNode<T> nodeI, DListNode<T> nodeJ);
	DListNode<T>* FindSet(DListNode<T> node); 
	DListNode<T>* FindSet(int nodeKey);
};

template <typename T>
ostream& operator<<(ostream& out, const DisjointSet<T>& ds) {
	int count = 0;
	vector<DListNode<T>*> newList = ds.getNodeLocator();

	for(int i=1;i<newList.size();i++) {
		if(newList[i]!=NULL && newList[i] -> getRepresentative()) {
			out << "Set " << count++ << ": (";
			DListNode<T>* j = newList[i] -> getRepresentative();
			while(j!=NULL) {
				out << j -> getElem() << ",";
				j = j -> getNext();
			}
			out << ")";
		}
	}
	return out;
}