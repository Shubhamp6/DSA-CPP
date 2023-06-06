#include <bits/stdc++.h>
using namespace std;

// T - O(n) S - O(n)

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n = 7, a[n] = {3, 5, 1, 7, 4, 9, 3};
    int maxProfit = 0, maxSoFar[n];
    maxSoFar[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > maxSoFar[i + 1])
            maxSoFar[i] = a[i];
        else
            maxSoFar[i] = maxSoFar[i + 1];
    }

    for (int i = 0; i < n; i++)
    {
        if (maxSoFar[i] - a[i] > maxProfit)
            maxProfit = maxSoFar[i] - a[i];
    }

    cout << maxProfit << endl;

    return 0;
}