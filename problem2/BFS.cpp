
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include "GraphADT.h"



void Graph::BFS(int startNode, int endNode, int relationships[]) {
    // visited[i] will be true if there is a
    // path from startNode to i
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // queue for Breadth First Search
    queue<int> q;

    // Mark the current node as visited and enqueue it
    
    visited[startNode] = true;
    q.push(startNode);

    // Create a vector to store the path
    vector<int> path;

    // BFS Loop
    while (!q.empty()) {
        // Dequeueing a vertice from queue
        int currNode = q.front();
        q.pop();

        // If the current node is the endNode, then the path is found!
        if (currNode == endNode) {
            //the path should be stored inside a vector
            path.push_back(currNode);
            int curr = endNode;
            while (curr != startNode) {
                for (int i = 0; i < V; i++) {
                    if (relationships[curr * V + i] == 1) {
                        curr = i;
                        path.push_back(curr);
                        break;
                    }
                }
            }
            // Print the path
            cout << "Path from node " << startNode << " to node " << endNode << ": ";
            for (int i = path.size() - 1; i >= 0; i--) {
                cout << path[i] << " ";
            }
            cout << endl;
            return;
        }


		// First getting all adjacent vertices of the dequeued vertices. Then if a vertice has not been visited then mark it as visisted and enqueue it.
        list<int>::iterator i;
        for (i = adj[currNode].begin(); i != adj[currNode].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                q.push(*i);
                // Store the parent of the current node in the relationships array
                relationships[*i * V + currNode] = 1;
            }
        }
		
    }
	// If there is no path between the two vertices, print that there is no path example of this could be from node 3 to 2.
	cout << "There is no path from node " << startNode << " to node " << endNode << endl;

}


