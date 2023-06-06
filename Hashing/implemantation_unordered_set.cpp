#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    unordered_set<int> s;
    s.insert(5);
    s.insert(10);
    s.insert(20);
    s.insert(25);
    s.erase(20);
    if (s.find(10) == s.end())
        cout << "Number not found" << endl;
    else
        cout << "Number is found" << endl;

    for (auto it = s.begin(); it != s.end();it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
    cout << s.count(10) << endl;
    s.clear();

    return 0;
}