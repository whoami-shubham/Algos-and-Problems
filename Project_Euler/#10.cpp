#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll A[1000001];
    for(ll i=0;i<1000001;i++){
        A[i] = i;
    }
    A[1] = 0;
    for(ll i=2;i<=sqrt(1000001);i++){
        ll j=2;
        while(j*i<1000001){
            A[i*j] = 0;
            j++;
        }
    }
    for(ll i=1;i<1000001;i++){
        A[i] = A[i] + A[i-1];
    }
    
    
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++){
        ll n;
        cin>>n;
        cout<<A[n]<<endl;
    }
    
    
    
    
    return 0;
}