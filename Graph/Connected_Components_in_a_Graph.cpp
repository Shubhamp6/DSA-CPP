#include <bits/stdc++.h>
using namespace std;

vector<int> vis;
vector<list<int>> v;

void dfs(vector<list<int>> &v, vector<int> &vis, vector<int> &c_cc, int src)
{
    c_cc.push_back(src);
    vis[src] = 1;
    for (auto it : v[src])
    {
        if (!vis[it])
        {
            dfs(v, vis, c_cc, it);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, e;
    cin >> n >> e;
    v.resize(n + 1);
    vis.resize(n + 1, 0);
    vector<vector<int>> cc;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int count = 0;
    vector<int> c_cc;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            count++;
            dfs(v, vis, c_cc, i);
            cc.push_back(c_cc);
            c_cc.clear();
        }
    }

    cout << cc.size() << "\n";
    for (auto c_cc : cc)
    {
        for (auto vertex : c_cc)
        {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}