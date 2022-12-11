#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include "GraphADT.h"

using namespace std;


void Graph::isFriendOrAdversary(int relationships[]) {
    // Keep track of the number of edges
    int edgeCount = 0;

    // Iterate through the array of relationships
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			// If there is an edge, increment the edgeCount
			if (relationships[i * V + j] == 1) {
				edgeCount++;
			}
		}
	}

    // Check if the number of edges is odd or even
    if (edgeCount % 2 == 0) {
        cout << "This is an adversary" << endl;
    }
	else{
        cout << "This is a friend" << endl;
    } 
    

	
	
    
}