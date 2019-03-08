#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll>prime;

int main() {
    prime.push_back(2);
    ll i=3,flag;
    while(prime.size()<=10000){
        flag = 0;
        for(ll j=0;j<prime.size() && prime[j]*prime[j]<=i;j++){
            if(i%prime[j]==0){
                flag = 1;
                break;
            }
        }
        if(!flag){
            prime.push_back(i);
        }
        i=i+2;
        
    }
    int t,T;
    cin>>T;
    for(t=0;t<T;t++){
        ll n;
        cin>>n;
        cout<<prime[n-1]<<endl;
    }
    
    
    return 0;
}
