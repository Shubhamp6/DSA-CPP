#include <bits/stdc++.h>
using namespace std;

/* The best case sinario of this algorithm is when every time pivot is at the center of array part(T - O(nlogn) S - O(logn)).
   The worst case sinario of this algorithm is when array is already sorted in this case pivot is always low(T - O(n^2) S - O(logn)). */

void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[low], i = low, j = high;
    while (i < j)
    {
        while (a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j)
        {
            swap(a, i, j);
        }
    }
    swap(a, low, j);
    return j;
}

void quick_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(a, low, high);
        quick_sort(a, low, pivot - 1);
        quick_sort(a, pivot + 1, high);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n = 100000;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i]=rand();
    }
    
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}