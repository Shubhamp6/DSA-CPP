#include <bits/stdc++.h>
using namespace std;

// T - O(n) S - O(1)

int search(int a[], int key)
{
    int i = 0;
    while (a[i] <= key)
    {
        if (a[i] == key)
        {
            return i;
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
    int index = search(a, key);
    cout << index << endl;
    return 0;
}