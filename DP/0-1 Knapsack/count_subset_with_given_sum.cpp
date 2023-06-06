#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, sum;
    cin >> n >> sum;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (a[i - 1] <= j)
                dp[i][j] = ((dp[i - 1][j - a[i - 1]]) + (dp[i - 1][j]));
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][sum] << endl;

    return 0;
}