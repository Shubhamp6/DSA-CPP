#include <bits/stdc++.h>
using namespace std;

// Complexity T - O(V+E) S - O(v)
class Graph
{
    int V;
    vector<list<int>> adj;

public:
    vector<bool> visited;
    stack<int> st;
    Graph(int V);

    void addEdge(int u, int v);
    void DFS(int v);
    void topologicalSort();
    void topologicalSortUtil(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
    visited.resize(V, false);
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::topologicalSort()
{
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            topologicalSortUtil(i);
    }
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
}

void Graph::topologicalSortUtil(int v)
{
    visited[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
            topologicalSortUtil(*i);
    }
    st.push(v);
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