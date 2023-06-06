#include <bits/stdc++.h>
using namespace std;

// T - O(n) S - O(n)

void previousSmaller(int a[], int n, int ps[])
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ps[i] = -1;
        }
        else
        {
            ps[i] = s.top();
        }
        s.push(i);
    }
}

void nextSmaller(int a[], int n, int ns[])
{
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }
        if (s.empty())
            ns[i] = n;
        else
            ns[i] = s.top();
        s.push(i);
    }
}

int largestRectangularArea(int a[], int n)
{
    int maxArea = 0;
    int ps[n], ns[n];
    memset(ns, 0, sizeof(ns));
    previousSmaller(a, n, ps);
    nextSmaller(a, n, ns);
    for (int i = 0; i < n; i++)
    {
        int area = (ns[i] - ps[i] - 1) * a[i];
        maxArea = max(area, maxArea);
    }
    return maxArea;
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
    cout << largestRectangularArea(a, n);
    return 0;
}