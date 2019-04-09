#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[20][20];

int main() {
   ll maximum=0,product;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            cin>>A[i][j];
        }
    }
    
    for(int i=0;i<20;i++){
        for(int x=0;x<20;x++){
                product = 1;
                for(int j=x;j<x+4 && j<20;j++){  // right
                    product = 1ll*product*A[i][j];
                }

                maximum = maximum>product?maximum:product;
                product = 1;

                for(int j=i;j<i+4 && j<20;j++){  // down
                    product = 1ll*product*A[j][x];
                }

                maximum = maximum>product?maximum:product;
                product = 1;

                for(int j=i,k=x;k>x-4 && j<i+4 && j<20 && k>=0;j++,k--){  // digonally left
                    product = 1ll*product*A[j][k];
                }

                maximum = maximum>product?maximum:product;
                product = 1;

                 for(int j=i,k=x;k<x+4 && j<i+4 && j<20 && k<20;j++,k++){  // digonally down
                    product = 1ll*product*A[j][k];
                }
                maximum = maximum>product?maximum:product;
        }
        
    }
    
    cout<<maximum<<"\n";
    
    
    
    
    
    
    return 0;
}
