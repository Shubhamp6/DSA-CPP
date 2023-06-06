#include <bits/stdc++.h>
using namespace std;

// T - O(n^2) S - O(1)

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, sum;
    cin >> n >> sum;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        int sum1 = 0;
        for (int j = i; j < n; j++)
        {
            sum1 += a[j];
            if (sum == sum1)
            {
                cout << "The sub array with given sum is from index " << i << " to index " << j << endl;
            }
        }
    }

    return 0;
}