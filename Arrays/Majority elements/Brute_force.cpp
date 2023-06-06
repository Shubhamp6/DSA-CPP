#include <bits/stdc++.h>
using namespace std;

// T = O(n^2) S = O(1)

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n = 5, a[n] = {5, 1, 4, 1, 1};
    int majorityEle, Max_count = 0, index;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
            }
        }
        if (count > Max_count)
        {
            Max_count = count;
            index = i;
            majorityEle = a[i];
        }
    }
    if (Max_count > n / 2)
        cout << majorityEle << " " << index << " " << Max_count;
    else
        cout << "No majority element found" << endl;

    return 0;
}