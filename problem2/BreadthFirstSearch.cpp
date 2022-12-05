// Create a time complexity analysis with O(-) notation
// For BFS, the time complexity is O(V + E) where V is the number of vertices in the graph and E is the number of edges in the graph.


#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include "GraphADT.h"



// Do a BFS search
void Graph::BFS(int s) {
	// Mark all the vertices as not visited
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	// Create a queue for BFS
	queue<int> queue;
	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push(s);
	// 'i' will be used to get all adjacent vertices of a vertex
	
	list<int>::iterator i;
	while (!queue.empty()) {
		// Dequeue a vertex from queue and print it
		s = queue.front();
		cout << s << " \n";
		queue.pop();
		// Get all adjacent vertices of the dequeued vertex s. If a adjacent has not been visited, then mark it visited and enqueue it
		for (i = adj[s].begin(); i != adj[s].end(); ++i) {
			if (!visited[*i]) {
				visited[*i] = true;
				queue.push(*i);
			}
		}
	}

	// amount search from starting node
	cout << "Amount of search from starting node: " << s << endl;

}

