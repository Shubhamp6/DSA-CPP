#include <bits/stdc++.h>
using namespace std;

double t[3000][3000];
int v[3000][3000];

// double solve(double p[], int n, int i, int h, double sum)
// {
//     if (i == n)
//     {
//         // cout << sum << endl;
//         if (h > (n / 2))
//             return sum;
//         else
//             return 0;
//     }
//     double withH, withoutH;
//     if (v[i + 1][h + 1] != -1)
//         withH = t[i + 1][h + 1];
//     else
//     {
//         withH = solve(p, n, i + 1, h + 1, sum * p[i]);
//         v[i + 1][h + 1] = 0;
//         t[i + 1][h + 1] = withH;
//         cout << withH << endl;
//     }
//     if (v[i + 1][h] != -1)
//         withoutH = t[i + 1][h];
//     else
//     {
//         withoutH = solve(p, n, i + 1, h, sum * (1 - p[i]));
//         v[i + 1][h] = 0;
//         t[i + 1][h] = withoutH;
//     }
//     return withH + withoutH;
// }

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    double p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    // memset(v, -1, sizeof(v));
    // cout << setprecision(8) << solve(p, n, 0, 0, 1) << endl;
    double dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = dp[0][i - 1] * (1 - p[i - 1]);
        for (int j = 1; j <= i; j++)
            dp[j][i] = dp[j][i - 1] * (1 - p[i - 1]) + dp[j - 1][i - 1] * p[i - 1];
    }

    double probabilty = 0;
    for (int i = (n / 2) + 1; i <= n; i++)
        probabilty += dp[i][n];

    cout << setprecision(10)  << probabilty << endl;

    return 0;
}