#include <bits/stdc++.h>
using namespace std;

// Complexity T - O(ElogV)

class Graph
{

public:
    int V;
    vector<vector<pair<int, int>>> adj;
    vector<bool> visited;
    Graph(int V);

    void addEdge(int v, int u, int w);
    void primsMST();
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
    visited.resize(V, false);
}

void Graph::addEdge(int v, int u, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::primsMST()
{
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    pq.push(make_pair(0, 0));
    int ans = 0;

    while (!pq.empty())
    {
        int v = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (visited[v])
            continue;
        ans += w;
        visited[v] = true;
        vector<pair<int, int>>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            int u = (*i).first;
            int wu = (*i).second;

            if (!visited[u])
            {
                pq.push(make_pair(wu, u));
            }
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL), cout.tie(NULL);
    int V = 9;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.primsMST();
    return 0;
}