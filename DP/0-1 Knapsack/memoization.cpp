#include <bits/stdc++.h>
#include <string.h>
using namespace std;
// Knapsack by memoization
// For matrix use the veriable changing in recursive function call as dimension
// Here n and w are changing so, dimension of dp matrix wil be w+1 and n + 1
int dp[1001][1001];
// Intialize every element of matrix by -1
int main()
{
    memset(dp, -1, sizeof(dp));
}

int Knapsack(int wet[], int val[], int w, int n)
{
    if (n == 0 || w == 0)
        return 0;

    // Main part
    if (dp[n][w] != -1)
        return dp[n][w];

    if (wet[n - 1] <= w)
        return dp[n][w] = max((val[n - 1] + Knapsack(wet, val, w - wet[n - 1], n - 1)), Knapsack(wet, val, w, n - 1));
    else if (wet[n - 1] > w)
        return dp[n][w] = Knapsack(wet, val, w, n - 1);
}
