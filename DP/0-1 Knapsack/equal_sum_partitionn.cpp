#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 2)
        cout << 0 << endl;
    else
    {
        int dp[n+1][(sum / 2) + 1];
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int i = 1; i < (sum / 2) + 1; i++)
            dp[0][i] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < (sum / 2) + 1; j++)
            {
                if (a[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - a[i-1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        cout << dp[n][sum / 2] << endl;
    }
    return 0;
}