#include <bits/stdc++.h>
using namespace std;

// T - O(log2(N)) S - O(1)

int infiniteSearch(int a[], int key)
{
    int low = 0, high = 1;
    while (a[high] <= key)
    {
        low = high;
        high = 2 * high;
    }
    return binarySearch(a, low, high, key);
}

int binarySearch(int a[], int l, int r, int key)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == key)
        {
            return key;
        }
        else if (a[mid] > key)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
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
    int index = infiniteSearch(a, key);
    cout << index << endl;
    return 0;
}