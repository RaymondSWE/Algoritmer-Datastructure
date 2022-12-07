/*
*	Function isAdversaryOrFriend:
* 
	To determine the time complexity of a function, 
	we need to analyze number of operations performed by function
	and how they dpend on the input size. Function isFriendOrAdversay 
	has a linear time complexity. Because the size of relationship array because of number of operations performed by the function in proportional to number of elements in array.
	

	Function BFS:
	
	 in each iteration of the while loop. In each iteration, the function dequeues a vertex from the queue, which takes constant time. It then iterates through the adjacency list of the dequeued vertex,
	 which takes time proportional to the number of vertices adjacent to the dequeued vertex. 
	 Since the number of vertices adjacent to a vertex is bounded by the number of vertices in the graph, the time complexity of the BFS function is linear in the number of vertices in the graph.
*/


#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include "GraphADT.h"

void Graph::timeComplexity() {
    // Create an array of relationships
    int relationships[] = { 0, 2 };

    // Perform a BFS starting at vertex 0
    BFS(0, relationships);

    // Calculate the time complexity
    int V = getNumNodes();
    int E = 0;
    for (int v = 0; v < V; ++v) {
        E += adj[v].size();
    }
    int timeComplexity = V + E;

    // Print the time complexity
    cout << "Time complexity: " << timeComplexity << endl;
}

