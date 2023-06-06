#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.front() << " " << q.back() << endl;

    q.pop();

    cout << q.empty() << endl;
    return 0;
}