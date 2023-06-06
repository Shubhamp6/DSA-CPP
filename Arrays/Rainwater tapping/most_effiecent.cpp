#include <bits/stdc++.h>
using namespace std;

// T - O(n) S - O(1)

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n = 8, a[8] = {3, 1, 2, 4, 0, 1, 3, 2};

    int waterTrapped = 0, left = 0, right = n - 1, maxLeft = a[0], maxRight = a[n - 1];

    while (left < right)
    {
        if (a[left] <= a[right])
        {
            left++;
            maxLeft = max(maxLeft, a[left]);
            waterTrapped += maxLeft - a[left];
        }
        else
        {
            right--;
            maxRight = max(maxRight, a[right]);
            waterTrapped += maxRight - a[right];
        }
    }
    cout << waterTrapped << endl;
    return 0;
}