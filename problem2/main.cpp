#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include "GraphADT.h"


using namespace std;


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
	int relationships[16] = {};
	// In BFS function, we will store the path from startNode to endNode in this vector
	g.BFS(2, 3, relationships);
	
	// Check if the given node is a friend or adversary, put the parameters: startNode and relationships
	g.isFriendOrAdversary(relationships);
}