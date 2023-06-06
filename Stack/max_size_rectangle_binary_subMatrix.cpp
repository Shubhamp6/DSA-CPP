#include <bits/stdc++.h>
using namespace std;

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
    int n, m;
    cin >> n >> m;
    int a[n][m],curRaw[m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < m; i++)
    {
        curRaw[i] = a[0][i];
    }

    int maxArea = largestRectangularArea(curRaw,m);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j])
                curRaw[j]++;
            else
                curRaw[j] = 0;
        }
        int curArea = largestRectangularArea(curRaw,m);
        maxArea = max(maxArea, curArea);
    }
    cout << maxArea << endl;

    return 0;
}