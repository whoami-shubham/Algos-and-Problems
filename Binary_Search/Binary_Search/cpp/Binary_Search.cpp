/* Binary Search Algorithm O(logn)

A : given sorted array 
x : element that we are searching for

*/
int Binary_Search(vector<int>& A,int x){
    int n = A.size();
    int left = 0, right = n-1;
    while(left<=right){
        int mid = (left + right)/2;
        if(A[mid]==x){
            return mid; // return position  of x
        }
        else if(A[mid]>x){
            right = mid-1;
        }
        else{
            left = mid + 1;
        }
    }
    return -1; // element is not present
}