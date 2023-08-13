//link:https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
//marked hard but vaise kaafi easy standard ques hai
class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>& matrix,vector<vector<int>> &dp){
        if(i<0 || j<0 || i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int res=1;
        for(int a=0;a<4;a++){
            int rr=i+dr[a];
            int cc=j+dc[a];
            if(rr>=0 && rr<m && cc>=0 && cc<n && matrix[rr][cc]>matrix[i][j]){
                res=max(res,1+solve(rr,cc,m,n,matrix,dp));
            }
        }
        return dp[i][j]=res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res=max(res,solve(i,j,m,n,matrix,dp));
            }
        }
        return res;
    }
};