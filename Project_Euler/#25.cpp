#include <bits/stdc++.h>
#define ll long long
using namespace std;

int digits(string s){
    return s.length();
}
string add(string a,string b);
ll Ans[5001];
int main() {

     // precompute answers

    Ans[1] = 1;
    int i = 2;
    string fib_cur="1",fib_prev="0",fib_next="1";
    ll f = 2;
    while(i<=5000){
          if(digits(fib_next)==i){
              Ans[i] = f;
              i++;
          }
          string temp = fib_cur;
          fib_cur = fib_next;
          fib_prev = temp;
          fib_next = add(fib_cur,fib_prev); // use string to avoid overflow
          f++;
    }
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int n;
        cin>>n;
        cout<<Ans[n]<<"\n";
    }
    
    return 0;
}

string add(string a,string b){
    // add two strings 
    int carry = 0;
    int n1 = a.length();
    int n2 = b.length();
    int i = n1-1;
    int j = n2-1;
    while(i>=0 && j>=0){
        int d = (a[i]-'0') + (b[j]-'0') + carry;
        carry = d/10;
        a[i] = char('0' + d%10);
        b[j] = char('0' + d%10);
        i--;
        j--;
    }
    while(j>=0){
        int d = (b[j]-'0') + carry;
        carry = d/10;
        b[j] = char('0' + d%10);
        j--;
    }
    while(i>=0){
        int d = (a[i]-'0') + carry;
        carry = d/10;
        a[i] = char('0' + d%10);
        i--;
    }
    if(carry>0){
               b = char('0'+carry) + b; 
               a = char('0'+carry) + a; 
        }
    if(a.length()>b.length()){
        return a;
    }
    else if(b.length()>a.length()){
        return b;
    }
    else{
        return a;
    }
}