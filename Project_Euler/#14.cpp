/*
* store the maximum Collatz sequence length for each index till the maximum size of array
* for each query if number is greater than size of array then bring number into
* range of size of  array then return count + Array[n] 
*
*/
#include<bits/stdc++.h>
#define ll  long long
using namespace std;
unsigned ll A[5000001];
unsigned ll Ans[5000001];
unsigned ll Collatz(unsigned ll n); 
int main(){
   memset(A,-1,sizeof(A));
   unsigned ll count = 1;
  for(int i=1;i<5000001;i=i*2){
      A[i] = count;
      count++;
  }
  for(int i=3;i<5000001;i++){
      A[i] = Collatz(i);
  }
   Ans[1] = 1;
   for(int i=2;i<5000001;i++){
      Ans[i] = A[i]>=A[Ans[i-1]]?i:Ans[i-1];
  } 
  
    unsigned ll t;
    cin>>t;
   for(ll j=0;j<t;j++){
       unsigned ll n;
       cin>>n;
       cout<<Ans[n]<<endl;
   }

    return 0;
}
unsigned ll Collatz(unsigned ll n){
 unsigned ll count=1,temp = n;
   if(n==1){
       return 1;
   }
   if(n<=5000000 && A[n]!=-1){
       return A[n];
   }
   if(n%2==0){
       temp = n/2;   
   }
   else{
       temp = 3*n + 1;
   }
     while(temp>5000000){

                if(temp%2==0)
                {
                    temp=temp/2;
                }
                else
                {
                    temp=temp*3+1;
                }
                count++;
    }
    A[n] = count + Collatz(temp);
    return A[n];
    

}