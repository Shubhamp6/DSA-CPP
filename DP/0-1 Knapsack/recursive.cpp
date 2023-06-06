#include<bits/stdc++.h>
using namespace std;
// Recursive function for knapsack
int recursiveKnapsack(int wet[], int val[], int w, int n)
{
    if (n == 0 || w == 0)
        return 0;
    if (wet[n - 1] <= w)
        return max((val[n - 1] + recursiveKnapsack(wet, val, w - wet[n - 1], n - 1)), recursiveKnapsack(wet, val, w, n - 1));
    else if (wet[n - 1] > w)
        return recursiveKnapsack(wet, val, w, n - 1);
}
