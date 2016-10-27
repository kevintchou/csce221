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
	DListNode<T>* FindSet(DListNode<T>& node);
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

template <typename T>
DisjointSet<T>::DisjointSet(int n) {
	nodeLocator.resize(n);
}

template <typename T>
DisjointSet<T>::~DisjointSet() {
	for (int i = 0; i<nodeLocator.size(); i++) {
		delete[] nodeLocator[i];
	}
	//nodeLocator.clear();
}

template<typename T>
vector<DListNode<T>*> DisjointSet<T>::getNodeLocator() const {
	return nodeLocator;
}

template <typename T>
DListNode<T>* DisjointSet<T>::MakeSet(int key, T node) {
	DListNode<T>* Node1 = new DListNode<T>(key,node,NULL,NULL);
	Node1 -> setTrailer(Node1);
	Node1 -> setRepresentative(Node1);

	if(nodeLocator.size()>key)
		nodeLocator[key] = Node1;
	else {
		nodeLocator.resize(key*2);
		nodeLocator[key] = Node1;
	}
}

template <typename T>
DListNode<T>* DisjointSet<T>::Union(DListNode<T> nodeI, DListNode<T> nodeJ) {
	if(nodeJ.getListSize()<nodeI.getListSize()) {
		nodeI.getTrailer() -> setNext(nodeJ.getRepresentative());
		nodeJ.setPrevious(nodeI.getTrailer());
		DListNode<T>* k = nodeJ.getNext();

		for(int i=0;i<nodeJ.getListSize()-1;++i) {
			k -> setRepresentative(nodeI.getRepresentative());
			k = k -> getNext();
		}

		nodeJ.setRepresentative(nodeI.getRepresentative());
		DListNode<T>* j = &nodeI;
		nodeI.setTrailer(k);
		nodeI.getRepresentative() -> setListSize(nodeJ.getListSize()+nodeI.getListSize());
		return nodeI.getRepresentative();
	}
	else {
		nodeJ.getTrailer() -> setNext(nodeI.getRepresentative());
		nodeI.setPrevious(nodeJ.getTrailer());
		DListNode<T>* k = nodeI.getNext();

		for(int i=0;i<nodeI.getListSize()-1;++i) {
			k -> setRepresentative(nodeJ.getRepresentative());
			k = k -> getNext();
		}

		nodeI.setRepresentative(nodeJ.getRepresentative());
		DListNode<T>* j = &nodeJ;
		nodeJ.setTrailer(k);
		nodeJ.getRepresentative() -> setListSize(nodeJ.getListSize()+nodeI.getListSize());
		return nodeJ.getRepresentative();
	}
}

template <typename T> 
DListNode<T>* DisjointSet<T>::FindSet(DListNode<T>& node) {
	return node.getRepresentative();
}

template <typename T>
DListNode<T>* DisjointSet<T>::FindSet(int nodeKey) {
	if (nodeLocator[nodeKey] != NULL)
		return nodeLocator[nodeKey]->getRepresentative();
}
