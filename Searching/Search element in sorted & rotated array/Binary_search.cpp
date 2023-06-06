#include <bits/stdc++.h>
using namespace std;

int search(int a[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        if (a[low] <= a[mid])
        {
            if (a[low] <= key && a[mid] > key)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (a[high] >= key && a[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n = 5, a[n] = {2, 3, 4, 5, 1}; // Sorted & 1 time rotated array
    int key;
    cin >> key;
    int index = search(a, n, key);
    cout << index << endl;
    return 0;
}