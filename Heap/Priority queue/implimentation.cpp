#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    priority_queue<int> pq;
    pq.push(5);
    pq.push(15);
    pq.push(10);
    cout << pq.size() << endl;
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}