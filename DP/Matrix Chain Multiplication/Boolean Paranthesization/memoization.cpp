#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001][2];

int solve(string s, int i, int j, bool isTrue)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
            return (s[i] == 'T');
        else
            return (s[i] == 'F');
    }
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    int ans = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        int lt, lf, rt, rf;
        if (dp[i][k - 1][1] != -1)
            lt = dp[i][k - 1][1];
        else
            lt = solve(s, i, k - 1, true);
        if (dp[i][k - 1][0] != -1)
            lf = dp[i][k - 1][0];
        else
            lf = solve(s, i, k - 1, false);
        if (dp[k + 1][j][1] != -1)
            rt = dp[k + 1][j][1];
        else
            rt = solve(s, k + 1, j, true);
        if (dp[k + 1][j][0] != -1)
            rf = dp[k + 1][j][0];
        else
            rf = solve(s, k + 1, j, false);
        if (s[k] == '&')
        {
            if (isTrue)
                ans += rt * lt;
            else
                ans += (lt * rf) + (lf * rt) + (lf * rf);
        }
        else if (s[k] == '^')
        {
            if (isTrue)
                ans += (lt * rf) + (lf * rt);
            else
                ans += (lt * rt) + (lf * rf);
        }
        else
        {
            if (isTrue)
                ans += (lt * rt) + (lt * rf) + (lf * rt);
            else
                ans += lf * rf;
        }
    }
    return dp[i][j][isTrue] = ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string s;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    cout << solve(s, 0, s.length() - 1, true) << endl;
    return 0;
}