#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull factorial_sum(ull n){
    vector<int>factorial;
    factorial.push_back(1);
    ull carry = 0,product,ans=0;
    for(ull i=2;i<=n;i++){
        ull j=0;
        while(j<factorial.size()){
            product = factorial[j]*i + carry;
            factorial[j] = product%10;
            carry = product/10;
            j++;
        }
        while(carry>0){
             factorial.push_back(carry%10);
             carry = carry/10;
        }
    }
    for(auto digit:factorial){
        ans = 1ull*(ans + digit);
    }
    
    return ans;
}


int main() {
    ull table[1001];
    for(int i=0;i<1001;i++){
        table[i] = factorial_sum(i);
    }
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int n;
        cin>>n;
        cout<<table[n]<<"\n";
    }
    
    
    return 0;
}
