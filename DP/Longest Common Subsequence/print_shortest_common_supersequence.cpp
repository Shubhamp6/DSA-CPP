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
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = n, j = m;
    vector<char> lcs;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            lcs.push_back(x[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                lcs.push_back(x[i - 1]);
                i--;
            }
            else
            {
                lcs.push_back(y[j - 1]);
                j--;
            }
        }
    }
    while (i > 0)
    {
        lcs.push_back(x[i - 1]);
        i--;
    }
    while (j > 0)
    {
        lcs.push_back(y[j - 1]);
        j--;
    }
    reverse(lcs.begin(), lcs.end());
    for (int k = 0; k < lcs.size(); k++)
        cout << lcs[k];
    cout << endl;

    return 0;
}