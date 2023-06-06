#include <bits/stdc++.h>
using namespace std;

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

    int ans = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        int lt = solve(s, i, k - 1, true);
        int lf = solve(s, i, k - 1, false);
        int rt = solve(s, k + 1, j, true);
        int rf = solve(s, k + 1, j, false);
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
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string s;
    cin >> s;
    cout << solve(s, 0, s.length() - 1, true) << endl;
    return 0;
}