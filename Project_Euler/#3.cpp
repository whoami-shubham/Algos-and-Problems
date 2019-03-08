#include<bits/stdc++.h>
#define ll long long
using namespace std;


bool isPrime(ll n);
int main() {
     int T;
     cin>>T;
     for(int t=0;t<T;t++){
         ll n;
         cin>>n;
         ll i=2,ans=2;
         if(isPrime(n)){
             ans = n;
         }
         else{
                 while(i<=sqrt(n)){
                     if(n%i==0 && isPrime(i)){
                         ans = ans>i?ans:i;
                 }
                     if((n%(n/i)==0) && isPrime((n/i))){
                         ans = ans>1ll*(n/i)?ans:1ll*(n/i);
                     }
                    i = i+1;
               }
         }
         cout<<ans<<endl;
     }
    return 0;
}
bool isPrime(ll n){
    if(n==1 || (n%2==0 && n!=2)){
        return false;
    }
    ll i=2;
    while(i<=sqrt(n)){
        if(n%i==0 || (n%(n/i)==0)){
            return false;
        }
        i = i%2==0?i+1:i+2;   // eliminate even numbers
    }
    return true;
}
