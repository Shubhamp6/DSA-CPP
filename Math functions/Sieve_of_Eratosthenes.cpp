#include<bits/stdc++.h>
using namespace std;

void sieveOfEratoSthenes(int n){
   bool isPrime[n+1];
   memset(isPrime,true,sizeof(isPrime));
   isPrime[0] = false;
   isPrime[1] = false;

   for (int  i = 2; i * i < n; i++)
   {
      for (int j = 2*i; j <=n; j += i)
      {
          isPrime[j]=false;
      }
      
   }

  for (int i = 1; i <= n; i++)
  {
      if (isPrime[i])
      {
          cout << i << endl;
      }
      
  }
  
   
}

int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL),cout.tie(NULL);
int n;
cin >> n;
sieveOfEratoSthenes(n);

return 0;
}