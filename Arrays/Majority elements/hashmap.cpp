#include <bits/stdc++.h>
using namespace std;

// T - O(n) S - O(n)

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n = 5, a[n] = {5, 1, 4, 1, 1};
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
        m[a[i]]++;
    int count = 0;
    for (auto i : m)
    {
        if (i.second > n / 2)
        {
            count = 1;
            cout << "Majority element is : " << i.first << endl;
        }
    }
    if (count == 0)
        cout << "No majority element exists" << endl;

    return 0;
}