// import Graph.cpp
// import BFS.cpp
#include <iostream>
#include "GraphADT.h"
using namespace std;
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.printGraph();
    cout << "Breadth First Traversal "
         << "(starting from vertex 2) \n";
    BFS(g, 2);
    return 0;
}
