//link: https://leetcode.com/problems/check-if-it-is-possible-to-split-array/submissions/
class Solution {
public:
    bool isValid(int i,int j,vector<int>& nums, int m){
        int sum=0;
        for(int ind=i;ind<=j;ind++){
            sum+=nums[ind];
        }
        return sum>=m;
    }
    bool solve(int i,int j,vector<int>& nums, int m,vector<vector<int>> &dp){
        if(i==j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(isValid(i,j,nums,m)==false) return false;
        //now ye pure array ka sum to hai m se zyada to isko split karke dekhte hai 
        //split is i..k and k+1..j
        for(int k=i;k<=j-1;k++){
            bool l=solve(i,k,nums,m,dp);
            bool r=solve(k+1,j,nums,m,dp);
            if(l&&r){
                return dp[i][j]=true;
            }
        }
        return dp[i][j]=false;
    }
    bool canSplitArray(vector<int>& nums, int m) {
        int n=nums.size();
        if(n<=2) return true;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,n-1,nums,m,dp);
    }
};