#include <bits/stdc++.h>
using namespace std;

// T - O(n^2) S -O(1)

int distinctElements(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int rep = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                rep = 1;
            }
        }
        if (rep == 0)
        {
            count++;
        }
    }
    return count;
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