#include <bits/stdc++.h>
using namespace std;
int Maximum_Sum_SubArray_1(vector<int>& v);  // O(n^3)
int Maximum_Sum_SubArray_2(vector<int>& v);  // O(n^2)
int Maximum_Sum_SubArray_3(vector<int>& v);  // O(n)

int main(){
    int n;
    cin>>n;
    vector<int>input(n);
    for(int i=0;i<n;i++){
    	cin>>input[i];
    }
    cout<<Maximum_Sum_SubArray_1(input)<<endl;
    cout<<Maximum_Sum_SubArray_2(input)<<endl;
    cout<<Maximum_Sum_SubArray_3(input)<<endl;

}

int Maximum_Sum_SubArray_1(vector<int>& v){
    int n = v.size();
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
    	for(int j=i;j<n;j++){
    		int sum = 0;
    		for(int k=i;k<=j;k++){
                sum = sum + v[k];
    		}
    		ans = max(ans,sum);
    	}
    }
    return ans;
}

int Maximum_Sum_SubArray_2(vector<int>& v){
	int n = v.size();
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
    	int sum = 0;
    	for(int j=i;j<n;j++){
    		sum = sum + v[j];
    		ans = max(ans,sum);
    	}
    }
    return ans;
}

int Maximum_Sum_SubArray_3(vector<int>& v){
	int n = v.size();
    int ans = INT_MIN;
    int dp[n];  //  we can solve without this array
    if(n>0){
    	dp[0] = v[0]>0?v[0]:0;
    }
    for(int i=1;i<n;i++){
    	dp[i] = dp[i-1]+v[i]>0?(dp[i-1]+v[i]):0;
    	ans = max(ans,dp[i]);
    }
    return ans;

}