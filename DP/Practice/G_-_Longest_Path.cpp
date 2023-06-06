#include <bits/stdc++.h>
using namespace std;

vector<int> v[100001];
vector<int> vis(100001, 0), dp(100001, 0);

int dfs(int i)
{
    if (vis[i])
        return dp[i];

    vis[i] = 1;
    int maxLength = 0;

    for (auto j : v[i])
        maxLength = max(maxLength, dfs(j) + 1);

    return dp[i] = maxLength;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    int maxLength = 0;
    for (int i = 1; i <= n; i++)
        maxLength = max(dfs(i), maxLength);

    cout << maxLength << endl;

    return 0;
}