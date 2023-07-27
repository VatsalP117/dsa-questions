//link: https://leetcode.com/problems/search-a-2d-matrix/submissions/
//solution of row_col_sorted.cpp works as well but this one is more optimal

Conditions: Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
therefore, if you open up the entire array and convert to a single 1d array it will be sorted 
so lets do exactly that but just in our minds 
so total elements = n*m (so high at n*m-1 index) 
amd just do normal binary search 
to convert index value (0...n*m-1) to (row,col) use this formula 
row_no=index/num_cols
col_no=index%num_cols
why this? basically number of elements in a row= number of columns wala funda so usse row number mil jayega and same logic for col_no


//beats 100%
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();//number of rows
        int n=matrix[0].size();//number of columns
        //number of elements in a row=n
        int low=0;
        int high=n*m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row=mid/n;
            int col=mid%n;
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;

    }