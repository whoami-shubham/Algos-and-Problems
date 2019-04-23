#include <bits/stdc++.h>
# define ll long long
using namespace std;

int main() {
   ll fact[13]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
   int T;
   cin>>T;
   for(int t=0;t<T;t++){
       ll n;
       vector<char>words = {'a','b','c','d','e','f','g','h','i','j','k','l','m'};
       cin>>n;
       string ans="";
       int i = 12;
       while(i>=0){
           ll index = (n-1)/(fact[i]);
           ans = ans + words[index];
           n = n - index*fact[i];
           words.erase(words.begin()+index,words.begin()+index+1);
           i--;
       }
       cout<<ans<<"\n";

   }

    return 0;
}
