#include <bits/stdc++.h>
using namespace std;

// T - O(n) S - O(1)

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n = 8, a[n] = {5, 2, 6, 1, 4, 7, 3, 6};
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[i - 1])
        {
            profit += (a[i] - a[i - 1]);
        }
    }

    cout << profit << endl;

    return 0;
}