int largestRectangleArea(vector<int> &A) {
    stack<int>s;
    A.push_back(0);
    int n = A.size();
    int i = 0;
    long long ans = n>0?A[0]:0;
    while(i<n){
        if(s.size()==0 || A[s.top()]<=A[i]){
            s.push(i);
            i++;
        }
        else{
            int height = A[s.top()];
            s.pop();
            int width = s.size()==0 ?i : i-s.top()-1;
            ans = ans< 1ll*height*width ? 1ll*height*width : ans;
         
        }
        
    }
    
    return ans;
}