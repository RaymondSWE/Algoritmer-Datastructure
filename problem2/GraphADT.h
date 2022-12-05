
#include <iostream>
#include <list>
using namespace std;
/* Graph class representing a
directed graph using
adjacency lists representation */
class Graph
{
private:
    int V; // No. of vertices
	list<int>* adj; // Pointer to an array containing adjacency lists

    /* Pointer to an
    array containing
    adjacency lists */
public:
    Graph(int V); // Constructor
    /* Add an edge to graph */
    void addEdge(int v, int w);
    // check if there is an  edge in graph
    bool isEdge(int v, int w);
    // get number of nodes
    int getNumNodes();
    /* print the adjacency list
    representation of graph*/
    void printGraph();
    
    // prints BFS traversal from a given source s
	void BFS(int s, int relationships[]);
	
	void isFriendOrAdversary(int s, int relationships[]);
};