#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int dp[n];
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int minJump = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (j > i)
                break;
            minJump = min(dp[i - j] + abs(a[i] - a[i - j]), minJump);
        }
        dp[i] = minJump;
    }

    cout << dp[n - 1] << endl;
    return 0;
}