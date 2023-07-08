//rotate image CW by 90 degrees
//so basically 1st column of ans=1st row of og matrix in reverse
//2nd col of ans=2nd row of og matrix in reverse

//bruteforce
void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(); //n==m for this ques
        vector<vector<int>> ans(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //matrix[i][j] is in ith row and jth col
                //it should now be in jth row 
                ans[j][n-1-i]=matrix[i][j];
            }
        }
        matrix=ans;
    }
//optimal in-place algo
//transpose then reverse all rows
 void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(); //n==m for this ques
        //transpose matrix: diagnol elements remain same
        //off diagnol mai swapped
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //reverse thr rows
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }