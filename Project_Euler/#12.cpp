/*
*  if a number have prime factors p1^n1 , p2^n2,...pn^nm
*  then number of divisors = (n1+1)*(n2+1)*...(nm +1 )
*/

#include <bits/stdc++.h>
#define ll long long
#define MAX_LENGTH 1001
using namespace std;
vector<ll>primes;
void prime_gen(ll n){
    if(primes.size()==0){
        primes.push_back(2);
        primes.push_back(3);
    }
    ll num = primes[primes.size()-1]+2 ;
    while(primes[primes.size()-1]<sqrt(n)){
        ll size = primes.size();
        bool flag = true;
        for(ll i=0;i<size && primes[i]<=sqrt(num);i++){
            if(num%primes[i]==0){
                flag = false;
                break;
            }
        }
        if(flag){
            primes.push_back(num);
        }
        num = num + 2;
    }
}
int count_divisors(ll n){
    prime_gen(n);
    ll i=0,count,ans=1,size=primes.size();
    while(i<size && primes[i]<=sqrt(n)){
        count = 1;
        while(n%primes[i]==0 && n>0){
            count++;
            n = n/primes[i];
        }
        ans = ans*count;
        i++;
    }
    ans = n!=1?ans*2:ans;
    return ans;
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll>table(1001,-1);
    ll sum=0,num=1,i=1,divisors=0;
    while(i<MAX_LENGTH){
                while(divisors>i && i<MAX_LENGTH){
                    table[i] = sum;
                    i++;
                }
                sum = sum + num;
                num++;
                ll j=1;
                divisors = count_divisors(sum);
             }
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        int n;
        cin>>n;
        
            cout<<table[n]<<"\n";
    
    }
    
    return 0;
}
