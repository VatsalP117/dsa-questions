//min coins to achieve a target. infinite supply of each coin
int f(int ind,int target,vector<int>& coins,vector<vector<int>> &dp){
        //f(ind,target)=min coins to achieve target using coins from [0...ind]

        //base case
        if(ind==0){
            if(target%coins[ind]!=0) return 1e8;
            else return (target/coins[ind]);
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        //
        int notTake=0+f(ind-1,target,coins,dp);
        int take=1e8;
        if(coins[ind]<=target) take=1+f(ind,target-coins[ind],coins,dp);
        return dp[ind][target]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= f(n-1,amount,coins,dp);
        if(ans>=1e8) return -1;
        return ans;
    }