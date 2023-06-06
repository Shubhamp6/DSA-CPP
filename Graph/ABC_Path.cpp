#include <bits/stdc++.h>
using namespace std;

void dfs(int h, int w, int sr, int sc, vector<string> &v, vector<int> &vis, int &ans)
{
    if (sr >= h || sc >= w)
    {
        return;
    }
    if (sr < 0 || sc < 0)
    {
        return;
    }
    if (vis[v[sr][sc]])
    {
        return;
    }
    if (v[sr][sc] != ans + 'A')
    {
        return;
    }

    ans++;
    v[sr][sc] = 1;
    dfs(h, w, sr-1, sc, v, vis, ans);
    dfs(h, w, sr + 1, sc, v, vis, ans);
    dfs(h, w, sr, sc - 1, v, vis, ans);
    dfs(h, w, sr, sc + 1, v, vis, ans);
    dfs(h, w, sr + 1, sc + 1, v, vis, ans);
    dfs(h, w, sr - 1, sc + 1, v, vis, ans);
    dfs(h, w, sr - 1, sc - 1,  v, vis, ans);
    dfs(h, w, sr + 1, sc - 1,  v, vis, ans);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int h, w;
    int T = 1;
    cin >> h >> w;
    while (h * w)
    {
        vector<string> v;
        int flag = 0, ia, ja, ans = 0;
        vector<pair<int, int>> p;
        for (int i = 0; i < h; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
            for (int j = 0; j < s.length(); j++)
            {
                if (s[j] == 'A')
                {
                    flag = 1;
                    p.push_back({i, j});
                }
            }
        }

        vector<int> vis(h*w,0);

        if (flag)
        {
            int maxAns = INT_MIN;
            for (auto posA : p)
            {
                dfs(h, w, posA.first, posA.second, v, vis, ans);
                maxAns = max(maxAns, ans);
                ans = 0;
            }
            cout << "Case " << T << ": " << maxAns << "\n";
        }
        else
        {
            cout << "Case " << T << ": 0"
                 << "\n";
        }
        cin >> h >> w;
    }
    return 0;
}