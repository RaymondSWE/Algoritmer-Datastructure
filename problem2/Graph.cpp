#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include "GraphADT.h"
using namespace std;

// Constructor
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
// Add an edge to graph
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w
    // to v’s list.
}
// check if there is an edge in graph
bool Graph::isEdge(int v, int w)
{
    list<int>::iterator i; // list
    // iterator used in loops
    for (i = adj[v].begin();
         i != adj[v].end(); ++i)
        if (w == *i)
            return (true);
    return (false);
}
// get number of nodes
int Graph::getNumNodes()
{
    return V;
}
// print the adjacency list
void Graph::printGraph()
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of node \n head ";
        // Iterate over adj[v]
        list<int>::iterator i;
        for (i = adj[v].begin();
             i != adj[v].end(); ++i)
        {
            cout << "-> " << *i;
            printf("\n");
        }
    }
}
// BFS implementation
void BFS(Graph g, int start)
{
    /* I need to implement a counter for even or odd, if even = adversary if odd number its a friend*/ 
    // queue for BFS
    queue<int> queue;
    // Mark all the vertices as not visited
    vector<bool> visited(g.getNumNodes(), false);
    // Mark the current node as visited and enqueue it
    visited[start] = true;
    queue.push(start);
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;
    while (!queue.empty())
    {
        // dequeue a vertex from queue and print it
        start = queue.front();
        cout << start << " ";
        queue.pop();
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = g.adj[start].begin();
             i != g.adj[start].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push(*i);
            }
        }
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Breadth First Search (starting from vertex 2): \n";
    BFS(g, 2);
    
    return 0;
}
