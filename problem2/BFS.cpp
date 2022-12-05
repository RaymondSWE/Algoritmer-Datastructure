// BFS implementation
void BFS(Graph g, int start)
{
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