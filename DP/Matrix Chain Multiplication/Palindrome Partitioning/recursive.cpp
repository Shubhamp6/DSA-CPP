#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string s, int i, int j)
{
    if (i >= j)
        return 1;
    if (s[i] == s[j])
        return isPalindrome(s, i + 1, j - 1);
    return 0;
}

int solve(string s, int i, int j)
{
    if (i >= j || isPalindrome(s, i, j))
        return 0;
    int mn = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = solve(s, i, k) + solve(s, k + 1, j) + 1;
        mn = min(mn, temp);
    }
    return mn;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string s;
    cin >> s;
    cout << solve(s, 0, s.length() - 1) << endl;
    return 0;
}