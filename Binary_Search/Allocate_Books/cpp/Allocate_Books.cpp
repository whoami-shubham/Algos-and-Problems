/*
* problem link https://www.interviewbit.com/problems/allocate-books/
*
*
*/

bool isPossible(vector<int> &books, int students,int pages){
    int students_required = 1;
    int n = books.size(),pages_sum=0;
    for(int i=0;i<n;){
        if(pages_sum+books[i]>pages){
            students_required++;
            pages_sum = 0;
        }
        else{
            pages_sum = pages_sum + books[i];
            i++;
        }
        if(students_required>students){
            break;
        }
    }
    return students_required<=students;
}
int Solution::books(vector<int> &A, int B) {
    if(B>A.size()){
        return -1;
    }
    int low = 0,high = INT_MAX,ans = 0;
    while(low<=high){
        int mid = (low+high)/2;
        if(isPossible(A,B,mid)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
