
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include "GraphADT.h"



// Do a BFS search
void Graph::BFS(int s, int relationships[]) {
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
		cout << "Node " << s << " Goes to: " << s + 1 << endl;
		
		queue.pop();
		// Get all adjacent vertices of the dequeued vertex s. If a adjacent has not been visited, then mark it visited and enqueue it
		for (i = adj[s].begin(); i != adj[s].end(); ++i) {
			if (!visited[*i]) {
				visited[*i] = true;
				queue.push(*i);
			}
		}
	}
	
	// Check if the last node visited is an adversary
	isFriendOrAdversary(s, relationships);


	// amount search from starting node
	cout << "Amount of search from starting node: " << s << endl;
	
}

