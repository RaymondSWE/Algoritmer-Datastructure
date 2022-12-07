#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include "GraphADT.h"


using namespace std;

// Driver code
int main() {
	// Create a graph
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 1);
	g.addEdge(1, 3);
	g.addEdge(2, 3);
	// print the graph
	// Create an array of relationships
	int relationships[] = { 0, 2 };

	g.BFS(0, relationships);
	
}
