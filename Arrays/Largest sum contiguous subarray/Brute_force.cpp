#include <bits/stdc++.h>
using namespace std;

// T - O(n^2) S - O(1)

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n = 6, a[n] = {-5, 4, 6, -3, 4, -1};
    int maxSum = a[0], sIndex, fIndex;
    for (int i = 0; i < n; i++)
    {
        int curSum = 0;
        for (int j = i; j < n; j++)
        {
            curSum += a[j];
            if (curSum >= maxSum)
            {
                maxSum = curSum;
                sIndex = i;
                fIndex = j;
            }
        }
    }

    cout << maxSum << " " << sIndex << " " << fIndex << endl;

    return 0;
}