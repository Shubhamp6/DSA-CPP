#include <bits/stdc++.h>
using namespace std;

// Complexity S - O(V^2)
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m; // n is number of vertices and m is number of edges
    cin >> n >> m;
    int graph[n + 1][m + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    return 0;
}