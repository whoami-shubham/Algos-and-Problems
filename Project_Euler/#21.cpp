#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    vector<ll>table(100001,0);
    vector<ll>sum(100001,0);
    for(int i=2;i<100001;i++){
        ll sum = 1;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                sum = sum + j;
            }
            if(i%(i/j)==0 && j!=(i/j)){
                sum = sum + i/j;
            }
        }
        table[i] = sum; 
    }
    for(int i=2;i<100001;i++){
        ll a = table[i];
        ll b = -1;
        if(a<100001){
            b = table[a];
        }
        if(b==i && i!=a){
            sum[i] =  i;
        }
        sum[i] = sum[i-1] + sum[i];
    }
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int n;
        cin>>n;
        cout<<sum[n]<<endl;

    }
    
    return 0;
}
