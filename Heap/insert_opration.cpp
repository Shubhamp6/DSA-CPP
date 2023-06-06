#include <bits/stdc++.h>
using namespace std;
#define MAX 100

void heapify(int a[], int n, int i)
{
    int parent = (i - 1) / 2;
    if (a[parent] > 0)
    {
        if (a[parent] < a[i])
        {
            swap(a[i], a[parent]);
            heapify(a, n, parent);
        }
    }
}

void insertInHeap(int a[], int &n, int key)
{
    n = n + 1;
    a[n - 1] = key;
    heapify(a, n, n - 1);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, a[MAX];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int key;
    cin >> key;
    insertInHeap(a, n, key);

    for (int i = 0; i < n; i++)
     cout << a[i] << " ";
    

    return 0;
}