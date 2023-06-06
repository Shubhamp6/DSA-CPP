#include <bits/stdc++.h>
using namespace std;

// O(2^n) n = length of string

void powerset(string s, int i, string cur)
{
    if (i == s.length())
    {
        cout << cur << ", ";
        return;
    }
    powerset(s, i + 1, cur + s[i]);
    powerset(s, i + 1, cur);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string s, cur;
    cin >> s;
    cout << "Powerset of set s = {" << s << "} is {";
    powerset(s, 0, cur);
    cout << "}." << endl;
    return 0;
}