#include <bits/stdc++.h>
#define ll long long
using namespace std;

unsigned ll digit_sum(unsigned ll n);
int main() {
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        unsigned ll n;
        cin>>n;
        cout<<digit_sum(n)<<endl;
    }
    return 0;
}
unsigned ll digit_sum(unsigned ll n){
    int len = floor(n*log10(2))+1;
    char number[len];
    sprintf(number,"%0.Lf",exp2((long double)n));
    unsigned ll sum =0;
    int i = 0;
    while(i<len && number[i]!='\0'){
        sum = sum + (number[i]-'0');
        i++;
    }
    return sum;
}
/*
another solution
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> xPowN(int x, int n){
    vector<int>ans;
    ans.push_back(1);
    for(int i=1;i<=n;i++){
            int temp = ans[0]*x;
            ans[0] = (temp)%10;
            int carry = temp/10;
            for(int j=1;j<ans.size();j++){
               temp = (ans[j]*x + carry);
               ans[j] = temp%10;
               carry = temp/10;
            }
            if(carry){
                ans.push_back(carry);
            }
    }
    return ans;
}
int digitSum(int n){
    vector<int>digits = xPowN(2,n);
    int ans = 0;
    for(auto d:digits){
        ans += d;
    }
    return ans;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int testCases;
    cin>>testCases;
    while(testCases>0){
        int n;
        cin>>n;
        cout<<digitSum(n)<<endl;
        testCases--;
    }
    return 0;
}
