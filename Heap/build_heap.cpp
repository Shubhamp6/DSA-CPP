#include <bits/stdc++.h>
using namespace std;
#define MAX 100

void heapify(int a[], int n, int i)
{
    int largest = i, l = i * 2 + 1, r = i * 2 + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        swap(a[largest], a[i]);

        heapify(a, n, largest);
    }
}

void buildHeap(int a[], int n)
{
    for (int i = (n/2)-1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, a[MAX];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    buildHeap(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}