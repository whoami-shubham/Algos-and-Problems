/* we have given following equations
*    a<b<c
*    a+b+c = n
*    a^2 + b^2 = c^2
*
*               a<b   ---- (1)
*               a<c   ---- (2)
*               
*    add (1) + (2)             
*    a+a<b+c
*    2a<b+c
*   add a both sides
*    3a<a+b+c
*    a<n/3
*   here  assume a  as constant for solve equation then there is only two variables b,and c
*   after solving a+b+c = n and a^2 + b^2 = c^2  
*   you will get b = (n^2 - 2*n*a )/(2*n - 2*a)
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll n,b,c,prod=-1;
        cin>>n;
        
            for(ll a=1;a<=n/3;a++){
                  b = (n*n - 2*n*a)/(2*n -2*a );
                  c = n-a-b;
                   if(a+b+c==n && (a*a + b*b) == (c*c)){
                       prod = prod>(1ll*a*b*c)?prod:(1ll*a*b*c);
                   }
                
            }
            cout<<prod<<endl;
        
        
    }
    
    return 0;
}
