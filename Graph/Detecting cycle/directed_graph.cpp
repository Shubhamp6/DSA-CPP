#include <bits/stdc++.h>
using namespace std;

// Complexity T - O(V+E)
class Graph
{
    int V;
    vector<list<int>> adj;

public:
    vector<bool> visited;
    vector<bool> recStack;

    Graph(int V);

    void addEdge(int u, int v);
    void DFS(int v);
    bool isCycle(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
    visited.resize(V, false);
    recStack.resize(V, false);
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

bool Graph::isCycle(int v)
{
    if (!visited[v])
    {
        visited[v] = true;
        recStack[v] = true;

        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i])
                return isCycle(*i);
            else if (recStack[*i])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << g.isCycle(2) << "\n";

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    cout << g2.isCycle(0) << "\n";
    return 0;
}