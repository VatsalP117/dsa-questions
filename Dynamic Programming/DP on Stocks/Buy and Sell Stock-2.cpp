//memoization
#include <bits/stdc++.h>
int f(int ind,int allowBuy,vector<int> &prices,vector<vector<int>> &dp,int n){
        //base case
        
        if(ind==n){
            return 0;
        }
        if(dp[ind][allowBuy]!=-1) return dp[ind][allowBuy];
        //
        
        //if allowed to buy
        if(allowBuy==1){
            return dp[ind][allowBuy]=max(-prices[ind]+f(ind+1,0,prices,dp,n),f(ind+1,1,prices,dp,n));
        }
        else{
            //can only sell or not sell
            return dp[ind][allowBuy]=max(prices[ind]+f(ind+1,1,prices,dp,n),f(ind+1,0,prices,dp,n));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
       return f(0,1,prices,dp,n);
    }


//tabulation
int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        //copy the base case from memoization
        dp[n][0]=0;
        dp[n][1]=0;

        //convert to for loops
        for(int i=n-1;i>=0;i--){
            dp[i][1]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
            dp[i][0]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
        }

       return dp[0][1];
    }
//space optimization
int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        vector<int> prev(2,0);
        vector<int> curr(2,0);
       
        //convert to for loops
        for(int i=n-1;i>=0;i--){
            curr[1]=max(-prices[i]+prev[0],prev[1]);
            curr[0]=max(prices[i]+prev[1],prev[0]);
            prev=curr;
        }

       return prev[1];
    }