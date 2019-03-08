/*
* for bruteforce solution O(n) time limit will exceed
*  use A.P(arithmetic progression) sum formula S(n) = n/2(2a + (n-1)d);
*/


#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll fun(ll n);
int main() {
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        ll n,ans=0;
        cin>>n;
        n = n>0?n-1:0;
        ans = fun(n);
        cout<<ans<<endl;
    }
    
    
    return 0;
}
ll fun(ll n){
    ll n1=n/3,n2=n/5,sum3=0,sum5=0,sum15=0,sum=0;
    sum3  = 1ll*((3+(n1*3))*n1)/2;
    sum5  = 1ll*((5+(n2*5))*n2)/2;
    sum15 = 1ll*((15 + 15*(n/15))*(n/15))/2;
    
    sum = sum3+sum5 - sum15; 
    return sum;
}