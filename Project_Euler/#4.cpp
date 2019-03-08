/*
*  find all pelindromes of 6 digit numbers and save that into a array
*  then sort the array to apply binary search then
*  for each query find largest pelindrome in  array less than N using binary search
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool isPelindrome(int n){
    string s = to_string(n);
    int i=0,j=s.length()-1;
    while(i<=j && s[i]==s[j]){
        i++;
        j--;
    }
    if(i>j){
        return true;
    }
    return false;
}

int main() {
    vector<int>pelindrome;
    for(int i=100;i<=999;i++){
            for(int j=100000/i;j<=999;j++){
                if(isPelindrome(i*j)){
                   pelindrome.push_back(i*j);
                    
                }
            }
        }
    sort(pelindrome.begin(),pelindrome.end());
     int T,t;
    cin>>T;
    for(t=0;t<T;t++){
        int n,ans=0,high=pelindrome.size()-1,low=0,mid;
        cin>>n;
        while(high>low){
            mid = (low+high)/2;
            if(pelindrome[mid]<n){
                low = mid+1;
                ans = max(ans,pelindrome[mid]);
            }
            else{
                high = mid-1;
            }
        }
        cout<<ans<<endl;
        
        
    }
    return 0;
}
