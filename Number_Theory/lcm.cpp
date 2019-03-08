/*
 *  as we know that lcm*hcf = a*b
 *
 */



#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b);
int lcm(int a,int b);
int main(){

	     int a,b;
	     cin>>a>>b;
             cout<<lcm(a,b)<<endl;
	     return 0;

}
int gcd(int a,int b){
	   if (a==0){
		    return b;
	      }

	     return gcd(b%a,a);

}
int lcm(int a,int b){
   int product = a*b;   
   int gcd_ = gcd(a,b);
   if (gcd_==0){
      return -1;
   }
   return product/gcd_;

}

