#include <bits/stdc++.h>
using namespace std;

// T - O(n) S -O(n)

int distinctElements(int a[], int n)
{
    unordered_set<int> set;
    for (int i = 0; i < n; i++)
        set.insert(a[i]);
    return set.size();
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
    cout << distinctElements(a, n) << endl;
    return 0;
}