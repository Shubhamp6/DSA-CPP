#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL),cout.tie(NULL);
   int n;
   cin >> n;
   int a[n];
   for (int i = 0; i < n; i++)
    cin >> a[i];
   
   int ans = 0;
   int count = 1;
   for (int i = 1; i < n; i++)
   {
      if(a[ans]==a[i]) count++;
      else count--;

      if(count==0){
        ans = i;
        count=1;
      }
   }

   if(count > 0){
   int check = 0;
   for (int i = 0; i < n; i++)
   {
     if(a[i]==a[ans]) check++;
   }
   if(check > (n/2)) cout << "Majority element in this array is :" << a[ans] ; 
   else  cout << "There is no majority element.!!!";
   }
   else  
   cout << "There is no majority element.!!!";
   
   
return 0;
}