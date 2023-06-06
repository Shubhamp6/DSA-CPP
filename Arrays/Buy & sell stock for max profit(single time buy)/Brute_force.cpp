#include <bits/stdc++.h>
using namespace std;

// T - O(n^2) S - O(1)

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n = 7, a[n] = {3, 5, 1, 7, 4, 9, 3};
    int maxProfit = 0, buyOn, sellOn;
    for (int i = 0; i < n; i++)
    {
        int profit = 0;
        for (int j = i; j < n; j++)
        {
            profit = a[j] - a[i];
            if (profit > maxProfit)
            {
                maxProfit = profit;
                buyOn = i;
                sellOn = j;
            }
        }
    }

    cout << maxProfit << " " << buyOn << " " << sellOn << endl;
    return 0;
}
