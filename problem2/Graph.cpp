#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include "GraphADT.h"

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}
void Graph::addEdge(int v, int w) {
	adj[v].push_back(w); // Add w 
	//to v’s list.
}
bool Graph::isEdge(int v, int w) {
	list<int>::iterator i; //list 
	// iterator used in loops
	for (i = adj[v].begin();
		i != adj[v].end(); ++i)
		if (w == *i) return (true);
	return (false);
}
int Graph::getNumNodes() {
	return V;
}
void Graph::printGraph() {
	for (int v = 0; v < V; ++v) {
		cout << "\n Adjacency list of node" << v << "\n head ";
		//Iterate over adj[v] 
		list<int>::iterator i;
		for (i = adj[v].begin();
			i != adj[v].end(); ++i) {
			cout << "-> " << *i;
			printf("\n");
		}
	}
}






