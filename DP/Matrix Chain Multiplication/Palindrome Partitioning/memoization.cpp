#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int isPalindrome(string s, int i, int j)
{
    if (i >= j)
        return 1;
    if (s[i] == s[j])
        return isPalindrome(s, i + 1, j - 1);
    return 0;
}

int solve(string s, int i, int j)
{
    if (i >= j || isPalindrome(s, i, j))
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mn = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int left, right;
        if (dp[i][k] != -1)
            left = dp[i][k];
        else
            left = solve(s, i, k);
        if (dp[k + 1][j] != -1)
            right = dp[k + 1][j];
        else
            right = solve(s, k + 1, j);
        int temp = left + right + 1;
        mn = min(mn, temp);
    }
    return dp[i][j] = mn;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string s;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    cout << solve(s, 0, s.length() - 1) << endl;
    return 0;
}