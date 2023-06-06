#include <bits/stdc++.h>
using namespace std;

//  T - O(n) S - O(n)

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n = 8, a[8] = {3, 1, 2, 4, 0, 1, 3, 2};

    int waterTapped = 0, left[n], right[n];

    left[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > left[i - 1])
            left[i] = a[i];
        else
            left[i] = left[i - 1];
    }

    right[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > right[i + 1])
            right[i] = a[i];
        else
            right[i] = right[i + 1];
    }

    for (int i = 0; i < n; i++)
    {
        waterTapped += (min(left[i], right[i]) - a[i]);
    }

    cout << waterTapped << endl;

    return 0;
}