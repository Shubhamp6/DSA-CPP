#include <bits/stdc++.h>
using namespace std;

int solve(string a, string b)
{
    if (a.compare(b) == 0)
        return 1;
    if (a.length() <= 1)
        return 0;
    int flag = 0;
    for (int i = 1; i < a.length(); i++)
    {
        if ((solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, a.length() - i), b.substr(i, a.length() - i))) || (solve(a.substr(0, i), b.substr(a.length() - i, i)) && solve(a.substr(i, a.length() - i), b.substr(0, a.length() - i))))
        {
            flag = 1;
            break;
        }
    }

    return flag;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string a, b;
    cin >> a >> b;
    if (a.length() != b.length() || a.length() == 0)
        cout << 0 << endl;
    cout << solve(a, b) << endl;
    return 0;
}