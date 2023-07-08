#include <bits/stdc++.h>
//memoization
int f(int ind,int prev_ind,vector<int> &nums,int n,vector<vector<int>> &dp){
        if(ind==n) return 0;
        if(dp[ind][prev_ind]!=-1) return dp[ind][prev_ind];
        int notTake=f(ind+1,prev_ind,nums,n,dp);
        int take=0;
        if(prev_ind==0 || nums[ind]>nums[prev_ind-1]){
            take=1+f(ind+1,ind+1,nums,n,dp);
        }
        return dp[ind][prev_ind]=max(take,notTake);
    }
    //prev_ind is shifted by 1 to the right
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0,0,nums,n,dp);
    }

