#include <bits/stdc++.h>
using namespace std;
// Eculidean algo for gcd
// Time complexity O(logn)
int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int a = 3, b = 16;
    printf("%d\n", gcd(24, 45));
    // Build-in function for gcd
    int gcd1 = __gcd(3, 15);
    printf("%d\n", gcd1);
    // for lcm
    int c = gcd(a, b);
    int lcm = (a / c) * b;
    printf("%d", lcm);

    return 0;
}