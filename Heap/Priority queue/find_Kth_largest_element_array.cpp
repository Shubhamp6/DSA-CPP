#include <bits/stdc++.h>
using namespace std;

int kthLargestEle(int a[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
        pq.push(-a[i]);
    for (int i = k; i < n; i++)
    {
        if ((-pq.top()) < a[i])
        {
            pq.pop();
            pq.push(-a[i]);
        }
    }
    return (-pq.top());
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << kthLargestEle(a, n, k) << endl;
    return 0;
}