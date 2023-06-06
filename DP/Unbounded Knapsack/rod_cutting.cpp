#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    int price[n], length[n];
    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int i = 0; i < n; i++)
        cin >> length[i];

    // Bottom-Up table
    int dp[n + 1][n + 1];

    // Initialization
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;
    for (int i = 0; i < n + 1; i++)
        dp[0][i] = 0;

    // processing
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (length[i - 1] <= j)
                dp[i][j] = max(price[i-1] + dp[i][j - length[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    // In bottom up aproach answer is at n+1 w+1 of dp matrix
    cout << dp[n][n] << endl;
    return 0;
}