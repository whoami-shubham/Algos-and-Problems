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