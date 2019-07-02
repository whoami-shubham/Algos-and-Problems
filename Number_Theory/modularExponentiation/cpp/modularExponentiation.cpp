/*
 *
 *  In modularExponentiation we reduce n to n/2 in each step where n>=0
 *  e.g  a^10  
 *
 *  a^10 =   (a^5*a^5)
 *  a^5  = a*(a^2*a^2)
 *  a^2  =   (a*a)
 *  a    = a*(1*1)
 *  
 *  at each step we take mod
 */

#include<bits/stdc++.h>
#define MOD  1000000007
using namespace std;
int modularExponentiation(int a,int n);

int main(){

int a,n;
cin>>a>>n;
cout<< modularExponentiation(a,n)<<endl;

return 0;

}

int modularExponentiation(int a,int n){
    if (n==0){
        return 1;
     }
    else if(n%2==0){
        return modularExponentiation(((a%MOD)*(a%MOD))%MOD,n/2); 
     }
    else{
        return ((a%MOD)*modularExponentiation((a%MOD)*(a%MOD),(n-1)/2))%MOD; 
    }
}
