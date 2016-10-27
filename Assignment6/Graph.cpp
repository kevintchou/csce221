#include "Graph.h"
#include "disjointset.h"
#include "TemplateDoublyLinkedList.h"
#include <iostream>

using namespace std;

bool sortingCompFunc (Edge* i, Edge* j)
  {
	return (i->weight < j->weight);
  }

void Graph::buildGraph() {
  if((n<0) || (e<0)){
    throw GraphException("either row or column is negative!");
  }
  //For all 
  for (int i=0; i<n; i++)
  {
	DListNode<Vertex>* Ver = new DListNode<Vertex>(i, Vertex(i));
	AdjacencyList.push_back(Ver);
  }  
}

void Graph::insertEdge(int i, int j, double w) {
  if(curEdges >= e){
    throw GraphException("edge number is not correct!");
  }
  Edge* temp = new Edge(i,j,w);
  EdgeList.push_back(temp);
  
  DListNode<Vertex>* Ver1 = AdjacencyList[i]->insert_after(j, Vertex(j));
  DListNode<Vertex>* Ver2 = AdjacencyList[j]->insert_after(i, Vertex(i));
  
  Ver1->getElem().setEdge(temp);
  Ver2->getElem().setEdge(temp);
  

  curEdges++; 
  return;
}

double Graph::getWeight(int i, int j) {
  
  DListNode<Vertex> *temp = AdjacencyList[i];

  while(temp != NULL) 
  {  
	if (temp->getElem().index == j)
	{
		if(temp->getElem().edge == NULL)
			return 0;
		else
			return temp->getElem().edge->weight;
	}
	
	temp = temp->getNext();
  }
  
  return 0;
}

void Graph::sortEdge() {
  std::sort(EdgeList.begin(), EdgeList.end(), sortingCompFunc);
}

double Graph::Value_Checker()
{
  double MST_val = 0;
  for (int w = 0; w <MST.size()-1; w++)
  {
	MST_val = MST_val + MST[w]->weight;
  }
  return MST_val;
}

double Graph::MSTAlgo() {
  
  DisjointSet<Vertex> Set(2);
  
    
  for (int i =0; i<AdjacencyList.size(); i++)
  {
	Set.MakeSet(i, Vertex(i));
	
  }
  
  sortEdge();
  
  for (int j = 0; j <EdgeList.size(); j++)
  {
	int u = EdgeList[j]->vertex_i;
	int v = EdgeList[j]->vertex_j;
	if (Set.FindSet(u) != Set.FindSet(v))
	{
		MST.push_back(EdgeList[j]);
		Set.Union(*(Set.FindSet(u)),*(Set.FindSet(v)));
	}
	
  }
  
  return Value_Checker();
}

