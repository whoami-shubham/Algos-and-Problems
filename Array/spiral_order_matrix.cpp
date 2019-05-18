/*

Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example:

Given the following matrix:

[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]

You should return

[1, 2, 3, 6, 9, 8, 7, 4, 5]


*/

vector<int> SpiralOrder(const vector<vector<int> > &A) {
    
    int rows    = A.size();
    int cols    = rows?A[0].size():0;
    int left    = 0;
    int right   = cols-1;
    int top     = 0;
    int bottom  = rows-1;
    int direction = 0;
    int RIGHT = 0,BOTTOM = 1,LEFT = 2, TOP = 3; 
    vector<int>ans;
    
    while(left<=right && top<=bottom){
        
        if(direction==RIGHT){
            
            for(int i = left;i<=right;i++){
                ans.push_back(A[top][i]);
            }
            top++;
            direction = BOTTOM;
            
        }
        else if(direction==BOTTOM){
            
            for(int i = top;i<=bottom;i++){
                ans.push_back(A[i][right]);
            }
            right--;
            direction = LEFT;
            
        }
        else if(direction==LEFT){
            
            for(int i = right;i>=left;i--){
                ans.push_back(A[bottom][i]);
            }
            bottom--;
            direction = TOP;
            
        }
        else{
            
            for(int i = bottom;i>=top;i--){
                ans.push_back(A[i][left]);
            }
            left++;
            direction = RIGHT;
            
        }
        
    }
    
    return ans;
    
}
