#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
    if (a==0){
        return b;
    }
    return gcd(b%a,a);
}
ll LCM[51];
int main() {
     LCM[1]=1;
     for(ll i=2;i<51;i++){
         LCM[i] = (1ll*i*LCM[i-1])/gcd(i,(LCM[i-1]));
     }
     int t,T;
    cin>>T;
    for(t=0;t<T;t++){
        int n;
        cin>>n;
        cout<<LCM[n]<<endl;
    }
    
    
    return 0;
}