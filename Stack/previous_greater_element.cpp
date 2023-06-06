#include <bits/stdc++.h>
using namespace std;

// T - O(n) S - O(n)

void previousGreater(int a[], int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top() <= a[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            cout << -1 << " ";
        }
        else
        {
            cout << s.top() << " ";
        }
        s.push(a[i]);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    previousGreater(a, n);
    return 0;
}