#include <bits/stdc++.h>
using namespace std;

// T - O(n) S - O(1)

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n = 6, a[n] = {-5, 4, 6, -3, 4, -1};
    int maxSum = a[0], curSum = 0;

    for (int i = 0; i < n; i++)
    {
        curSum += a[i];
        if (curSum >= maxSum)
            maxSum = curSum;
        if (curSum < 0)
            curSum = 0;
    }

    cout << maxSum << endl;
    return 0;
}