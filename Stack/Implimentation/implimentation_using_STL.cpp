#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    s.pop();

    cout << s.top() << " " << s.size() << endl;
    return 0;
}