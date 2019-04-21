#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll sum_of_proper_divisors(ll n){
    ll sum = 1;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            sum = sum + i;
        }
        if(n%(n/i)==0 && (n/i)!=i){
            sum = sum + (n/i);
        }
    }
    return sum;
    
}
int main() {
    vector<int>abundant_numbers;
    vector<bool>ansers(100001,false);
    for(int i=12;i<100001;i++){
        if(sum_of_proper_divisors(i)>i){
            abundant_numbers.push_back(i);
        }
    }
    int size = abundant_numbers.size(),i=0;
    while(i<size){
        int j = i;
        while(j<size && (abundant_numbers[i]+abundant_numbers[j]<100001)){
              ansers[abundant_numbers[i]+abundant_numbers[j]] = true;
              j++;
        }
        i++;
    }
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int n;
        cin>>n;
        string ans = ansers[n]?"YES":"NO";
        cout<<ans<<"\n";
    }
    
    return 0;
}
