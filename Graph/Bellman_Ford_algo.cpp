#include <bits/stdc++.h>
using namespace std;

//Complexity T - O(E*V)
// It is not as efficient as Dijkstra's algo but it work when edges have nagetive weights while Dijkstra's don't
void BellmanFord(int Graph[][3], int V, int E, int src)
{
    int dis[V];
    memset(dis, INT_MAX, V);
    dis[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            if ((dis[Graph[j][0]] != INT_MAX) && (dis[Graph[j][0]] + Graph[j][2] < dis[Graph[j][1]]))
                dis[Graph[j][1]] = dis[Graph[j][0]] + Graph[j][2];
        }
    }

    for (int i = 0; i < E; i++)
    {
        if (dis[Graph[i][0]] != INT_MAX && dis[Graph[i][0]] + Graph[i][2] < dis[Graph[i][1]])
        {
            cout << "There is negative cycle present so Bellman-Ford Algorith cannot work" << endl;
            return;
        }
    }

    for (int i = 0; i < V; i++)
    {
        cout << i << " " <<dis[i] << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int V = 5;
    int E = 8;

    int Graph[][3] = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

    BellmanFord(Graph, V, E, 0);
    return 0;
}