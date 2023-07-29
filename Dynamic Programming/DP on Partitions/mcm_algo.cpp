
class Solution{
public:
    int solve(int arr[],int i,int j,vector<vector<int>> &dp){
        //base case
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp_ans=solve(arr,i,k,dp)+solve(arr,k+1,j,dp)+(arr[i-1]*arr[k]*arr[j]);
            ans=min(ans,temp_ans);
        }
        return dp[i][j]=ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(N,-1));
        return solve(arr,1,N-1,dp);
    }
};