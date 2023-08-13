//link:https://leetcode.com/problems/visit-array-positions-to-maximize-score/description/
// You are given a 0-indexed integer array nums and a positive integer x.

// You are initially at position 0 in the array and you can visit other positions according to the following rules:

// If you are currently in position i, then you can move to any position j such that i < j.
// For each position i that you visit, you get a score of nums[i].
// If you move from a position i to a position j and the parities of nums[i] and nums[j] differ, then you lose a score of x.
// Return the maximum total score you can get.

// Note that initially you have nums[0] points.


class Solution {
public:
    bool sameParity(int a,int b){
        return ((a%2)==(b%2));
    }
    long long solve(int ind,int p,int x,int n,vector<int>& nums,vector<vector<long long>> &dp){
        //base lite
        if(ind==n){
            return 0;
        }
       
        if(dp[ind][p]!=-1)return dp[ind][p];
        //notTake
        long long notTake=solve(ind+1,p,x,n,nums,dp);
        //take
        long long take=0;
        if(nums[ind]%2==p){
            take=nums[ind]+solve(ind+1,p,x,n,nums,dp);
        }
        else{
            take=nums[ind]-x+solve(ind+1,nums[ind]%2,x,n,nums,dp);
        }
        if(take>notTake) return dp[ind][p]=take;
        else return dp[ind][p]=notTake;
    }
    long long maxScore(vector<int>& nums, int x) {
        int n=nums.size();
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return nums[0]+solve(1,nums[0]%2,x,nums.size(),nums,dp);
    }
};