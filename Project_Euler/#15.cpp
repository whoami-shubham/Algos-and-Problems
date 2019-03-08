#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
ll A[1000][1000];
ll path(ll left , ll down);
int main() {
    memset(A,-1,sizeof(A));
    ll t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll n, m;
        cin>>n>>m;
        cout<<path(n,m)<<endl;
    }
    return 0;
}
ll path(ll left , ll down){
    if (left==0 && down==0){
        return 1;
    }
    if(left<0 || down<0){
        return 0;
    }
    if(A[left][down]!=-1){
        return A[left][down];
    }
    A[left][down] =  (path(left-1,down) + path(left,down-1))%mod;
    return A[left][down];
}