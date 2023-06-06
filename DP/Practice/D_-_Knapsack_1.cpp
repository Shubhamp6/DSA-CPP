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
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];

    int dp[n + 1][weight+1];
    memset(dp, 0, sizeof(dp));
    // for (int i = 0; i < n + 1; i++)
    //     dp[i][0] = 0;
    // for (int i = 0; i < weight + 1; i++)
    //     dp[0][i] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < weight + 1; j++)
        {
            if (w[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j - w[i - 1]] + v[i - 1], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
            // cout << dp[i][j] << endl;
        }
    }

    cout << dp[n][weight] << endl;

    return 0;
}