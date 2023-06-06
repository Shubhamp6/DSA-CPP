#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int a, b, n, ans = 0;
    cin >> a >> b;
    n = a ^ b;
    /** while(n != 0){
        if (n & 1 != 0)
        {
            ans++;
        }
        n = n >> 1;
        
    } O(log2(n)+1)**/

    while (n != 0)
    {
        n = n & (n-1); // This opration clear the least signaficance set bit
        ans++;
    } // In this approach number of time loop run is equal to number of 1 is binary represntation of n
    

    cout << ans << endl;
    return 0;
}