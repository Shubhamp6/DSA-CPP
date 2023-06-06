#include<bits/stdc++.h>
using namespace std;


int returns(int amount,float factor = 1.04){
    return amount * factor;
}

// By writing const before variable name make sure that its value will not change in function
// This is know as constant argument
void a(int const m){
   // m=m*10;
}
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL),cout.tie(NULL);

// if you not pass the value of variable default argument is use  like :-
cout << returns(100000) << endl;
// if you pass the value of variable  passed value is use  like :-
cout << returns(100000,1.1) << endl;
return 0;
}