#include <bits/stdc++.h>
using namespace std;

// Complexity S - O(E+V)
void addEdge(vector<int> graph[], int v, int u)
{
    graph[v].push_back(u);
    graph[u].push_back(v);
}

void printGraph(vector<int> graph[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << "\n Adjacency list of vertex " << i
             << "\n head ";
        for (auto x : graph[i])
            cout << "-> " << x;
        cout << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int V = 5; // V is number of vertices
    vector<int> graph[V];
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph, V);
    return 0;
}