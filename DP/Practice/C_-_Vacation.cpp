#include <bits/stdc++.h>
using namespace std;

// int t[100001][3];
// int solve(int a[][3], int n, int skip, int ind)
// {
//     if (ind == n - 1)
//     {
//         int maxEl = INT_MIN;
//         for (int i = 0; i < 3; i++)
//         {
//             if (i == skip)
//                 continue;
//             maxEl = max(a[ind][i], maxEl);
//         }
//         t[ind][skip] = maxEl;
//         return maxEl;
//     }
//     int maxE = 0;
//     for (int i = 0; i < 3; i++)
//     {
//         if (i == skip)
//             continue;
//         if (t[ind + 1][i] != -1)
//             maxE = max(maxE, a[ind][i] + t[ind + 1][i]);
//         else
//             maxE = max(maxE, a[ind][i] + solve(a, n, i, ind + 1));
//     }

//     if (skip != 3)
//         t[ind][skip] = maxE;
//     return maxE;
// }

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    int a[n][3];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    // memset(t, -1, sizeof(t));
    // cout << solve(a, n, 3, 0) << endl;

    int dp[n][3];

    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = a[i][0] + max(dp[i - 1][2], dp[i - 1][1]);
        dp[i][1] = a[i][1] + max(dp[i - 1][2], dp[i - 1][0]);
        dp[i][2] = a[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << endl;

    return 0;
}