#include "Graph.h"
#include "disjointset.h"
#include <iostream>
#include <algorithm>

using namespace std;

bool sorting(Edge* i,Edge* j) {
  return(i->weight<j->weight);
}

void Graph::buildGraph() {
  if((n<0) || (e<0)){
    throw GraphException("either row or column is negative!");
  }
  for(int i=0;i<n;i++) {
    DListNode<Vertex>* v = new DListNode<Vertex>(i,Vertex(i));
    AdjacencyList.push_back(v);
  }   
}

void Graph::insertEdge(int i, int j, double w) {
  if(curEdges >= e){
    throw GraphException("edge number is not correct!");
  }
  Edge* g = new Edge(i,j,w);
  EdgeList.push_back(g);
  DListNode<Vertex>* v1 = AdjacencyList[i]->insert_after(j,Vertex(j));
  DListNode<Vertex>* v2 = AdjacencyList[j]->insert_after(i,Vertex(i));
  v1->getElem().setEdge(g);
  v2->getElem().setEdge(g);

  curEdges++; 
  return;
}

double Graph::getWeight(int i, int j) {
  DListNode<Vertex> *v = AdjacencyList[i];

  while(v!=NULL) {
    if(v->getElem().index==j) {
      if(v->getElem().edge==NULL)
        return 0;
      else
        return v->getElem().edge->weight;
    }
    v = v->getNext();
  }
  return 0;
}

void Graph::sortEdge() {
  std::sort(EdgeList.begin(),EdgeList.end(),sorting);
}

double Graph::checkValue() {
  double val = 0;

  for(int i=0;i<MST.size()-1;i++) {
    val = val+MST[i]->weight;
  }
  return val;
}

double Graph::MSTAlgo() {
  DisjointSet<Vertex> Set(2);

  for(int i=0;i<AdjacencyList.size();i++) {
    Set.MakeSet(i,Vertex(i));
  }
  sortEdge();

  for(int j=0;j<EdgeList.size();j++) {
    int a = EdgeList[j]->vertex_i;
    int b = EdgeList[j]->vertex_j;

    if(Set.FindSet(a)!=Set.FindSet(b)) {
      MST.push_back(EdgeList[j]);
      Set.Union(*(Set.FindSet(a)),*(Set.FindSet(b)));
    }
  }
  return checkValue();
}


  