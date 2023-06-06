#include <bits/stdc++.h>
using namespace std;

// T - O(n) S - O(1)

int majorityElement(int a[], int n)
{
    int index = 0, count = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[index] == a[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            index = i;
            count = 1;
        }
    }

    if (count > 0)
        return a[index];
    cout << "No majority element exists" << endl;
    return -1;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n = 5, a[n] = {5, 1, 4, 1, 1};
    cout << majorityElement(a, n) << endl;

    return 0;
}