#include <bits/stdc++.h>
using namespace std;

// T - O(log2(N)) S - O(log2(N))

int binary_search(int a[], int l, int r, int key)
{
    int mid = (l + r) / 2;
    if (l <= r)
    {
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] > key)
        {
            return binary_search(a, l, mid - 1, key);
        }
        else
        {
            return binary_search(a, mid + 1, r, key);
        }
    }
    return -1;
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
    int key;
    cin >> key;
    int index = binary_search(a, 0, n - 1, key);
    cout << index << endl;
    return 0;
}