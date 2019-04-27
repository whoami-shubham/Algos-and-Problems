/*

Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

*/

int singleNumber(const vector<int> &A) {
    int ans = 0;
    int n = A.size();
    for(int i=0;i<31;i++){
        int ones=0,zeros=0;
        for(int j=0;j<n;j++){
            if((A[j]<<i)&1){   
                ones++;
            }
            else{
                zeros++;
            }
        }
        if(ones%3!=0){
            ans = ans + pow(2,i);
        }
    }
    return ans;
}
