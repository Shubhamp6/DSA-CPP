#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL),cout.tie(NULL);
deque<int> dp;
dp.push_front(1);
dp.push_back(2);

cout << dp.front() << " " << dp.back();

dp.pop_front();
dp.pop_back();
return 0;
}