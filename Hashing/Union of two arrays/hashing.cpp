#include <bits/stdc++.h>
using namespace std;

// T - O(n+m) S -O(n+m)

int distinctElements(int a[], int b[], int n, int m)
{
    unordered_set<int> set;
    for (int i = 0; i < n; i++)
        set.insert(a[i]);
    for (int i = 0; i < m; i++)
        set.insert(b[i]);
    return set.size();
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
    cout << distinctElements(a, b, n, m) << endl;
    return 0;
}