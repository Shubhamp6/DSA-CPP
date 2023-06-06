#include <bits/stdc++.h>
using namespace std;

int jos(int n, int k)
{
    if (n == 1)
        return 0;
    return ((jos(n - 1, k)+k) % n);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    cout << jos(n, k) << endl;
    return 0;
}