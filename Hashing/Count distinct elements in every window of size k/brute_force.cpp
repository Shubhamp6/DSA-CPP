#include <bits/stdc++.h>
using namespace std;

// T - O((n-k+1)*n^2) S - O(1)

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

    for (int i = 0; i < n - k + 1; i++)
    {
        int ans = 0;
        for (int j = i; j < k + i; j++)
        {
            int rep = 0;
            for (int l = i; l < j; l++)
            {
                if (a[j] == a[l])
                {
                    rep = 1;
                }
            }
            if (rep == 0)
                ans++;
        }
        cout << ans << endl;
    }

    return 0;
}