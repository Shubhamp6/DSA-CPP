#include <bits/stdc++.h>
using namespace std;

int intersect(int a[], int b[], int n, int m)
{
    unordered_set<int> set;
    int count = 0;
    for (int i = 0; i < n; i++)
        set.insert(a[i]);
    for (int i = 0; i < m; i++)
    {
        if (set.find(b[i]) != set.end())
        {
            count++;
            set.erase(b[i]);
        }
    }
    return count;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    cout << intersect(a, b, n, m) << endl;
    return 0;
}