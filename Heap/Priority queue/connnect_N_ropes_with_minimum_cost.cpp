#include <bits/stdc++.h>
using namespace std;

// T - O(nlogn)

int minCost(int a[], int n)
{
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
        pq.push(-a[i]);
    int ans = 0;
    while (pq.size() > 1)
    {
        int first = (-pq.top());
        pq.pop();
        int second = (-pq.top());
        pq.pop();
        int sum = first + second;
        ans += sum;
        pq.push(-sum);
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << minCost(a, n) << endl;
    return 0;
}