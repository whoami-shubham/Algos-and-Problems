
/*
 *  
 *  It can be used for find prime number . since we are using array
 *  to store previous prime numbers we wouldn't be able to  use this method to 
 *  check whether a number is prime or not if number is greater than size of array.
 */

#include<bits/stdc++.h>
using namespace std;
bool Primes[100000000];
bool seive(int n);

int main(){
memset(Primes,true,sizeof(Primes));
Primes[0] = Primes[1] = false;
int n;
cin>>n;
cout<<seive(n)<<endl;

return 0;

}
bool seive(int n){

	for(int i=2;i<=sqrt(n);i++){
		int j = 2;
		for(;j*i<=n;j++){
           		Primes[j*i] = false;
		}
	}
    return Primes[n];

}
