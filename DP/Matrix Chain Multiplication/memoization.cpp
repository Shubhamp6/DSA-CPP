#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int solve(int a[], int i, int j)
{
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mn = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = solve(a, i, k) + solve(a, k + 1, j) + a[i - 1] * a[k] * a[j];
        mn = min(mn, temp);
    }
    return dp[i][j] = mn;
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
    memset(dp, -1, sizeof(dp));
    cout << solve(a, 1, n - 1) << endl;
    return 0;
}