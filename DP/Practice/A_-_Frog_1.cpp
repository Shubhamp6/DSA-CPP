#include <bits/stdc++.h>
using namespace std;

int solve(int a[], int pos, int n)
{
    if (pos == 0)
        return 0;
    if (pos == 1)
        return abs(a[0] - a[1]);
    return min(abs(a[pos] - a[pos - 1]) + solve(a, pos - 1, n), abs(a[pos] - a[pos - 2]) + solve(a, pos - 2, n));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int dp[n];
    dp[0] = 0;
    dp[1] = abs(a[0] - a[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
    }

    // cout << solve(a, n-1, n) << endl;
    cout << dp[n - 1] << endl;
    return 0;
}