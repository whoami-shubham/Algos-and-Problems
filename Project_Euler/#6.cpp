/*
*  sum of n numbers = n*(n+1)/2 
*  sum of square of n numbers = n*(n+1)(2*n+1)/6 
*
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        ll n;
        cin>>n;
        ll sum_square,square_sum;
        sum_square = (n*(n+1)/2)*(n*(n+1)/2);
        square_sum = n*(n+1)*(2*n+1)/6;
        cout<<(sum_square - square_sum)<<endl;
    }
    
    return 0;
}