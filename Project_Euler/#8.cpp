#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll Largest_product(string s,int n,int k);
int main() {
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int n,k;
        string number;
        cin>>n>>k;
        cin>>number;
        cout<<Largest_product(number,n,k)<<endl;
    }
    return 0;
}
ll Largest_product(string s,int n,int k){
    ll max_product =0;
    for(int i=0;i<n-k+1;i++){
        ll product=1;
        for(int j=i;j<i+k;j++){
            product = 1ll*product * (s[j]-'0');
        }
        max_product = max_product>product?max_product:product;
    }
    return max_product;
}