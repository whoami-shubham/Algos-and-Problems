#include <bits/stdc++.h>
#define ll long long
using namespace std;

int recurring_cycle(int num,int denum);

int main() {
    ll Ans[10001];
    Ans[4] = 3;
    ll cur = 3,prev=3,len=1;
    ll d = 5;
    while(d<10001){
        ll temp = recurring_cycle(1,d);
        if(temp>len){
            prev = cur;
            cur = d;
            len = temp;
        }
        Ans[d] = cur!=d?cur:prev; // read question carefully  d<N not d<=N
        d++;
    }
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int n;
        cin>>n;
        cout<<Ans[n]<<endl;
    }
    
    return 0;
}

int recurring_cycle(int num,int denum){
       int rem = num%denum;
       map<int,int>m;
       int i = 0,ans=0;
       while(rem!=0){
           rem = rem*10;
           if(m.find(rem)==m.end()){
                  m[rem] = i;
                  
           }
           else{
                ans = i-m[rem]+1;
                break;
           }
           i++;
           rem = rem%denum;
       }
       return ans;

}
