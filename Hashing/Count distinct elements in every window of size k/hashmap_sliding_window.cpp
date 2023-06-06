#include<bits/stdc++.h>
using namespace std;

// T - O(n) S - O(k)

void slidingWindow(int a[],int n,int k){
    unordered_map<int ,int> m;
    for (int i = 0; i < k; i++)
     m[a[i]]++;
    cout << m.size() << endl;
    for (int i = k; i < n; i++)
    {
        if (m[a[i-k]]==1)
         m.erase(m[a[i-k]]);
        else
         m[a[i-k]]--;
        
        m[a[i]]++;
        cout << m.size() << endl;
        
    }
    
    
}

int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL),cout.tie(NULL);
int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
 
slidingWindow(a,n,k);
return 0;
}