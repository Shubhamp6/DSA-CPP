#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, i, mask;
    cin >> n >> i;
    mask = 1 << i;
    if ((n & mask) == 0)
    {
        cout << "The ith bit is 0" << endl;
    }
    else
        cout << "The ith bit is 1" << endl;

    return 0;
}

// Using bit masking we can get optimized code
// i specified with indexing starting with 0