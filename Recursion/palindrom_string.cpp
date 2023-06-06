#include <bits/stdc++.h>
using namespace std;

// O(n) n = length of string

bool isPelindrome(string s, int l, int r)
{
    if (l >= r)
        return true;
    if (s[l] != s[r])
        return false;
    return isPelindrome(s, l + 1, r - 1);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string s;
    int l = 0, r;
    cin >> s;
    r = (s.length() - 1);
    cout << isPelindrome(s, l, r) << endl;
    return 0;
}