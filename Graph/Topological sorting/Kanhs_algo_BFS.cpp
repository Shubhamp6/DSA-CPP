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
    void topologicalSort();
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

void Graph::topologicalSort()
{
    vector<int> inDeg(V, 0);
    for (int u = 0; u < V; u++)
    {
        for (auto it : adj[u])
            inDeg[it]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (!inDeg[i])
            q.push(i);
    }

    int count = 0;
    vector<int> topoOrder;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (auto it : adj[u])
        {
            if (--inDeg[it] == 0)
                q.push(it);
        }
        count++;
    }

    if (count != V)
        cout << "There is a cycle in graph" << endl;

    for (int i = 0; i < topoOrder.size(); i++)
    {
        cout << topoOrder[i] << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    g.topologicalSort();
    return 0;
}