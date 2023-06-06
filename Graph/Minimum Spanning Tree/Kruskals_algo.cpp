#include <bits/stdc++.h>
using namespace std;
#define V 5
int parent[V];

int find(int i)
{
    while (parent[i] != i)
    {
        i = parent[i];
    }
    return i;
}

void union1(int x, int y)
{
    int a = find(x);
    int b = find(y);
    parent[a] = b;
}

void KruskalMST(int cost[][V])
{
    int minCost = 0;

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int edge_count = 0;
    while (edge_count < V - 1)
    {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (find(i) != find(j) && cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        union1(a, b);
        cout << edge_count++ << " (" << a << ", " << b << ") " << min << endl;
        minCost += min;
    }
    cout << "Total cost is " << minCost;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int cost[][V] = {
        {INT_MAX, 2, INT_MAX, 6, INT_MAX},
        {2, INT_MAX, 3, 8, 5},
        {INT_MAX, 3, INT_MAX, INT_MAX, 7},
        {6, 8, INT_MAX, INT_MAX, 9},
        {INT_MAX, 5, 7, 9, INT_MAX},
    };

    // Print the solution
    KruskalMST(cost);
    return 0;
}