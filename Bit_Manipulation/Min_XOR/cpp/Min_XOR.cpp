/*

Given an array of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value.

*/


int MinXor(vector<int> &A) {
    sort(A.begin(),A.end());
    int  ans = INT_MAX;
    int n = A.size();
    for(int i=1;i<n;i++){
        ans = min(ans,A[i]^A[i-1]);
    }
    return ans;
}
