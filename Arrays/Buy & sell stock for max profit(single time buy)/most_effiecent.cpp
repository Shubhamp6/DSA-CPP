#include <bits/stdc++.h>
using namespace std;

// T - O(n) S - O(1)

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n = 7, a[n] = {3, 5, 1, 7, 4, 9, 3};
    int maxProfit = 0, minSoFar = a[0];
    for (int i = 1; i < n; i++)
    {
        minSoFar = min(minSoFar, a[i]);
        int profit = a[i] - minSoFar;
        maxProfit = max(maxProfit, profit);
    }

    cout << maxProfit << endl;

    return 0;
}