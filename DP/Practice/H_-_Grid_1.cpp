#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

// int t[1001][1001];

// int solve(vector<string> v, int n, int m, int i, int j)
// {
//     if (v[i][j] == '#')
//         return 0;
//     if (i == 0 && j == 0)
//         return 1;
//     int a1 = 0, a2 = 0;
//     if (i - 1 > -1 && j > -1 && v[i - 1][j] == '.')
//     {
//         if (t[i - 1][j] != -1)
//             a1 = t[i - 1][j];
//         else
//             a1 = solve(v, n, m, i - 1, j) % MOD;
//     }
//     if (j - 1 > -1 && i > -1 && v[i][j - 1] == '.')
//     {
//         if (t[i][j - 1] != -1)
//             a2 = t[i][j - 1];
//         else
//             a2 = solve(v, n, m, i, j - 1) % MOD;
//     }
//     return t[i][j] = ((a1 + a2) % MOD);
// }

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    // memset(t, -1, sizeof(t));
    // cout << solve(v, n, m, n - 1, m - 1) << endl;

    int dp[n][m];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i - 1 > -1 && j > -1 && v[i - 1][j] == '.')
            {
                (dp[i][j] += (dp[i - 1][j] % MOD)) % MOD;
            }
            if (j - 1 > -1 && i > -1 && v[i][j - 1] == '.')
            {
                (dp[i][j] += (dp[i][j - 1] % MOD)) % MOD;
            }
        }
    }

    cout << dp[n - 1][m - 1] % MOD << endl;

    return 0;
}