#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, i, mask;
    cin >> n >> i;
    mask = 1 << i;
    n = n | mask;
    cout << n << endl;
    return 0;
}

// set ith bit means making ith bit 1 if its not otherwise keeping it as it is.
// Using bit masking we can get optimized code
// i specified with 0 indexing 