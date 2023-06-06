#include <bits/stdc++.h>
using namespace std;

void heapify(int a[], int n, int i)
{
    int r = i * 2 + 1, l = i * 2 + 2;
    int largest = i;
    if (l < n && a[largest] < a[l])
        largest = l;
    if (r < n && a[largest] < a[r])
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    heapSort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}