#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string a, b;
    cin >> a >> b;
    int dp[a.length() + 1][b.length() + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < a.length() + 1; i++)
    {
        for (int j = 1; j < b.length() + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = a.length(), j = b.length();
    string s;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            s += a[i - 1];
            i--;
            j--;
        }
        else if (dp[i][j - 1] > dp[i - 1][j])
            j--;
        else
            i--;
    }
    reverse(s.begin(),s.end());

    cout << s << endl;

    return 0;
}