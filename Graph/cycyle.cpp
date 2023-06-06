#include <bits/stdc++.h>
using namespace std;

int dfs(int v, vector<list<int>> &c, vector<int> &vis, int parent)
{

    vis[v] = 1;
    int isCycle = 0;
    for (auto i : c[v])
    {
        cout << v << endl;
        if (!vis[i])
            isCycle |= dfs(i, c, vis, v);
        if (parent != i)
            return true;
    }
    return isCycle;
}

int solve(int A, vector<vector<int>> &B)
{
    if (A <= 2)
        return 0;
    vector<list<int>> c;
    for (int i = 0; i < B.size(); i++)
    {
        int a  = B[i][0],b = B[i][1];
        c[a].push_back(b);
        c[b].push_back(a);
        cout << 1 << endl;
    }
    

    vector<int> vis;
    vis.resize(A + 1, 0);
    int isCycle = 0;
    for (int i = 1; i <= A; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, c, vis, -1))
                isCycle = 1;
        }
    }
    return isCycle;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int A, m;
    cin >> A >> m;
    vector<vector<int>> B(2);
    B[0].resize(m,0);
    B[1].resize(m,0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        B[i].push_back(a);
        B[i].push_back(b);
    }

    cout << 43 << solve(A,B);


    return 0;
}