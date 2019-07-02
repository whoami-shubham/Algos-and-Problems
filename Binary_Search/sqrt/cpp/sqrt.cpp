int sqrt(int A) {
    long long low = 1,high = A;
    while(low<=high){
        long long mid = (low+high)/2;
        if(mid*mid==A){
            return mid;
        }
        else if(mid*mid>A){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return high;
}