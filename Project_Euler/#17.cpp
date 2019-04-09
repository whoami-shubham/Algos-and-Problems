#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll nums[4] = {1000000000000,1000000000,1000000,1000};
string words[] = {"Zero ","One ","Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ","Eleven ",  "Twelve ", "Thirteen ","Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
string tenth[] = {"dummy","data","Twenty ","Thirty ", "Forty ", "Fifty ","Sixty ", "Seventy ", "Eighty ", "Ninety "};
string to_words(ll n);
string solve(ll n);
int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}

string to_words(ll n){
   string ans="";
   
    while(n>=0){
        int msb;
        if(n/100>0){
            msb = n/100;
            ans = ans + words[msb] + "Hundred ";
            n = n - msb*100 ;
            n = n==0?-1:n;
        }
        else{
            if(n/10>1){
                msb = n/10;
                ans = ans + tenth[msb];
                n = n - msb*10;
                if(n>0){
                    ans = ans + words[n];
                }
                n = -1;
            }
            else{
                ans = ans + words[n];
                n = -1;
            }
        }
        
    }
    return ans;
    
}

string solve(ll n){
    string ans="";
    while(n>=0){
            int i=0;
            ll msb;
            while(i<4 && (n/nums[i])==0){
                i++;
            }
            msb = i<4?(n/nums[i]):n;
            if(i<4){
                n = msb*nums[i]==n?-1: n - msb*nums[i];
            }
            else{
                n=-1;
            }
            ans = ans + to_words(msb);
           
           if(i>=4){
               return ans;
           }
           switch(nums[i]){
               case 1000000000000: 
                       ans = ans + "Trillion ";
                       break;
               case 1000000000:
                       ans = ans + "Billion ";
                       break;
               case 1000000:
                       ans = ans + "Million ";
                       break;
               case  1000:
                      ans  = ans + "Thousand ";
           }
        
        
    }
    return ans;
}
