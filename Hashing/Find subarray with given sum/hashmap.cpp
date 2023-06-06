#include <bits/stdc++.h>
using namespace std;

void subArraySum(int a[], int n, int sum)
{
    int curSum = 0, start = 0, end = -1;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        curSum += a[i];
        if (curSum == sum)
        {
            start = 0;
            end = i;
            break;
        }
        if (map.find(curSum - sum) != map.end())
        {
            start = map[curSum - sum] + 1;
            end = i;
            break;
        }
        map[curSum]=i;
    }
    if (end == -1)
        cout << "Subarray does not exist" << endl;
    else
        cout << "Subarray start from " << start << " to " << end << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, sum;
    cin >> n >> sum;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    subArraySum(a, n, sum);
    return 0;
}