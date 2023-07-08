    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();//number of rows
        int n=matrix[0].size();//number of columns
        vector<int> result;
        //approach is fro the outermost square:right,bottom,left,up
        //then move to the next inner square
        int top=0;
        int left=0;
        int bottom=m-1;
        int right=n-1;
        while (top <= bottom && left <= right) {
        // Traverse top row
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
        top++;

        // Traverse right column
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;

        // Traverse bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Traverse left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    } 
        

        
    return result;

    }