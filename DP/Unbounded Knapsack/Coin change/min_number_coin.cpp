#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, sum;
    cin >> n >> sum;
    int coin[n];
    for (int i = 0; i < n; i++)
        cin >> coin[i];

    int dp[n + 1][sum + 1];
    for (int i = 0; i < sum + 1; i++)
        dp[0][i] = INT_MAX - 1;
    for (int i = 1; i < n + 1; i++)
        dp[i][0] = 0;
    for (int i = 1; i < sum + 1; i++)
    {
        if (i % coin[0])
            dp[1][i] = INT_MAX - 1;
        else
            dp[1][i] = i / coin[0];
    }

    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coin[i - 1] <= j)
                dp[i][j] = min(1 + dp[i][j - coin[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][sum] << endl;

    return 0;
}