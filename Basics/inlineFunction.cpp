#include<bits/stdc++.h>
using namespace std;
// Used to reduce run time when we are calling function multiple times 
// It replace funtion call with actual function code
// It can be used when function has very few lines of code
// Do not use it for recursion and while working with static value
inline int product(int a,int b){
    return a*b;
}
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL),cout.tie(NULL);
int a=9,b=1;
cout << product(a,b) << endl;
cout << product(a,b) << endl;
cout << product(a,b) << endl;
cout << product(a,b) << endl;
cout << product(a,b) << endl;
cout << product(a,b) << endl;
cout << product(a,b) << endl;
return 0;
}