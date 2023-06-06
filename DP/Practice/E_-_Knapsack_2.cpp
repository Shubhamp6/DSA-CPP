#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, weight;
    cin >> n >> weight;

    int v[n], w[n];
    int val = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
        val += v[i];
    }

    int dp[n + 1][val + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < val + 1; i++)
        dp[0][i] = INT_MAX - 1;
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < val + 1; j++)
        {
            if (v[i - 1] <= j)
                dp[i][j] = min(dp[i - 1][j - v[i - 1]] + w[i - 1], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int ans = INT_MIN;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < val + 1; j++)
        {
            if (dp[i][j] <= weight)
                ans = max(ans, j);
        }
    }

    cout << ans << endl;

    return 0;
}