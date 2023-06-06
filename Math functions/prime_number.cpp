#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    int isnotprime = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            isnotprime++;
        }
    }

    if (isnotprime != 0 || n == 1)
    {
        printf("Number is not prime\n");
    }
    else
        printf("Number is prime\n");

    return 0;
}