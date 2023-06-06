// Find the number of ways to travel from (N-1,M-1) to (0,0) with condition that you can take rigth angle turns only
#include <bits/stdc++.h>
using namespace std;

int ways(int N, int M)
{
    if (N == 1 || M == 1)
        return 1;
    return ways(N - 1, M) + ways(N, M - 1);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    cout << ways(N, M) << endl;
    return 0;
}