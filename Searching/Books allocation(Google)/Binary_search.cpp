#include <bits/stdc++.h>
using namespace std;

// T - O(nLogn) S - O(1)

bool isFeasible(int a[], int n, int k, int res)
{
    int student = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + a[i] > res)
        {
            student++;
            sum = a[i];
        }
        else
            sum += a[i];
    }

    return k <= student;
}

int minPages(int a[], int n, int k)
{
    int min = a[0], max = a[0], res;
    for (int i = 1; i < n; i++)
    {
        if (min < a[i])
            min = a[i];
        max += a[i];
    }
    while (min <= max)
    {
        int mid = (min + max) / 2;
        if (isFeasible(a, n, k, mid))
        {
            res = mid;
            max = mid - 1;
        }
        else
            min = mid + 1;
    }
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << minPages(a, n, k) << endl;
    return 0;
}
