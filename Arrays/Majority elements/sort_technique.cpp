#include <bits/stdc++.h>
using namespace std;

// T - O(nlogn) S - O(1)

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n = 5, a[n] = {5, 1, 4, 1, 1};
    sort(a, a + n);
    int majorityEle, Max_count = 0, num = a[0], count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == num)
            count++;
        else
        {
            num = a[i];
            count = 1;
        }
        if (count > Max_count)
        {
            Max_count = count;
            majorityEle = a[i];
        }
    }

    if (Max_count > n / 2)
        cout << majorityEle << " " << Max_count;
    else
        cout << "No majority element found" << endl;

    return 0;
}