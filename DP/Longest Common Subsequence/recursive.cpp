#include <bits/stdc++.h>
using namespace std;

int lcs(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (x[n - 1] == y[m - 1])
        return 1 + lcs(x, y, n - 1, m - 1);
    else
        return max(lcs(x, y, n - 1, m), lcs(x, y, n, m - 1));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string x, y;
    cin >> x >> y;
    int lcsLength = lcs(x, y, x.length(), y.length());
    cout << lcsLength << endl;
    return 0;
}