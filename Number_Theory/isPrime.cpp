/*
 *  Bruteforce Approach
 *
 */

#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n);

int main(){
  int n;
  cin>>n;
  cout<<isPrime(n)<<endl;


 return 0;
}

bool isPrime(int n){

  if (n==1 || (n%2==0 && n!=2)){ // eliminate all even numbers except 2
    return false;
  }

  for(int i=1;i<=sqrt(n);i=i+2){  // take only odd numbers
         if(i==1){
	    continue;
	   }
       if((n%i==0) || (n%(n/i)==0)){
          return false;
       }
  }

  return true;
}



