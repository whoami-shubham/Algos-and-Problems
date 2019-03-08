#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        ll n;
        cin>>n;
        ll sum=2,fib0=1,cur_fib=2;
        while(cur_fib<n){
            cur_fib = fib0 + cur_fib;
            sum += (cur_fib%2==0) && (cur_fib<n) ?cur_fib:0;
            fib0 = cur_fib - fib0;
        }
        cout<<sum<<endl;
    }
    
    return 0;
}