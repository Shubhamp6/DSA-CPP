#include <bits/stdc++.h>
using namespace std;

// T - O(nlogn) S - O(logn)

void merge(int a[], int l, int mid, int r)
{
    int b[r + 1];
    int i = l, j = mid+1, k = l;
    while (i <= mid && j <= r)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    if (i > mid)
    {
        while (j <= r)
        {
            b[k++] = a[j++];
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k++] = a[i++];
        }
    }
    for (k = l; k <= r; k++)
        a[k] = b[k];
}

void merge_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n = 5, a[n] = {2, 6, 4, 1, 8};
    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}