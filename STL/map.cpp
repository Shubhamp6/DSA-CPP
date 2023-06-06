#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    // Map is a special kind of STL container which store elements as key-values pair. No two mapped values can have same key.
    // syntax map<firstDatatype, secondDatatype> name;
    // declration name[key]=value;
    map<int, string> erno;
    erno[100] = "shubham";
    // For size name.size(); O(1)
    int n = erno.size();
    // for deltion name.erase(key); O(logn)
    return 0;
}