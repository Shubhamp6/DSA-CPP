#include<bits/stdc++.h>
using namespace std;
#define ll int long long

#define num 1000000007
ll Moduloarithmetic(ll x, ll n){
    ll res=1;
    while (n!=0)
    {
        if ((n&1) !=0)
        {
            res = (res * (x % num))%num;
        }
       x = (x%num * x%num)%num;
       n=(n>>1); 
    }
    return res;
}

// time complexity O(logn)

int binaryExponentiation(int x,int n)/*x^n*/
{
  if (n == 0)
  {
      return 1;
  }

  if (n%2 == 0)
  {
      return binaryExponentiation(x*x,n/2);
  }

  return x*binaryExponentiation(x*x,(n-1)/2);
  
  
}

// iterative:- x^n
int BinaryExponentiation(int x, int n){
    int res=1;
    while (n!=0)
    {
        if ((n&1) !=0)
        {
            res*=x;
        }
       x*=x;
       n=(n>>1); 
    }
    return res;
}


int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL),cout.tie(NULL);
ll a,b;
cin >> a >> b;
cout << Moduloarithmetic(a,b) << endl;
return 0;
}