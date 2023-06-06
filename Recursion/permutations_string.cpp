#include <bits/stdc++.h>
using namespace std;

// O(n*n!) n = length of string

string swap(string s,int l,int r){
    char temp = s[l];
    s[l] = s[r];
    s[r] = temp;
    return s;
}

void permutations(string s, int l,int r){
    if (l == r)
    {
        cout << s << " ";
        return;
    }
    for (int i = l; i <= r; i++)
    {
        s = swap(s,l,i);
        permutations(s,l+1,r);
        s = swap(s,l,i);
    }
    
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string s;
    int l = 0, r;
    cin >> s;
    r = (s.length() - 1);
    permutations(s,l,r);
    return 0;
}