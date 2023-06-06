#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string x, y;
    cin >> x >> y;
    int n = x.length(), m = y.length();
    int dp[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;
    for (int i = 0; i < m + 1; i++)
        dp[0][i] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = 0;
        }
    }

    int maxLength = INT_MIN;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            maxLength = max(maxLength, dp[i][j]);
        }
    }

    cout << maxLength << endl;

    return 0;
}