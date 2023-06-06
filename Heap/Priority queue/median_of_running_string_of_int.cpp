#include <bits/stdc++.h>
using namespace std;

void printMedian(double a[], int n)
{
    priority_queue<double> s;
    // Minheap priority can also be implimented through
    priority_queue<double, vector<double>, greater<double>> g;

    double med = a[0];
    s.push(a[0]);
    cout << med << endl;
    for (int i = 1; i < n; i++)
    {
        double x = a[i];
        if (s.size() > g.size())
        {
            if (x < med)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);
            med = (s.top() + g.top()) / 2.0;
        }
        else if (s.size() == g.size())
        {
            if (x < med)
            {
                s.push(x);
                med = s.top();
            }
            else
            {
                g.push(x);
                med = g.top();
            }
        }
        else
        {
            if (x > med)
            {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
            {
                s.push(x);
            }
            med = (s.top() + g.top()) / 2.0;
        }
        cout << med << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    double a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    printMedian(a, n);
    return 0;
}