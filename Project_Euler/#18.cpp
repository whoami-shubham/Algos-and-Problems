#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll solve(vector<vector<int> >& M,int row,int dir,int n){
    if(row==n && (dir<=n && dir>=0)){
        return M[row][dir];
    }
    if(row>n || dir<0 || dir>n || M[row][dir]==-1){
        return 0;
    }
    return M[row][dir] + max(solve(M,row+1,dir+1,n),solve(M,row+1,dir,n));
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<vector<int> >M(n+1,vector<int>(n+1,-1));
        for(int j=0;j<n;j++){
            for(int k =0;k<=j;k++){
                cin>>M[j][k];
            }
        }
        cout<<solve(M,0,0,n-1)<<endl;
    }
    
    return 0;
}
