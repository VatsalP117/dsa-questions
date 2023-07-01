#include <bits/stdc++.h>
//memoization
int f(int ind,int allowBuy,int cap,vector<int> &prices,int n,vector<vector<vector<int>>> &dp){
        if(ind==n) return 0;
        if(cap==0) return 0;
        if(dp[ind][allowBuy][cap]!=-1) return dp[ind][allowBuy][cap];
        if(allowBuy==1){
            return dp[ind][allowBuy][cap]=max(-prices[ind]+f(ind+1,0,cap,prices,n,dp),f(ind+1,1,cap,prices,n,dp));
        }
        else{
            return dp[ind][allowBuy][cap]=max(prices[ind]+f(ind+1,1,cap-1,prices,n,dp),f(ind+1,0,cap,prices,n,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,prices,n,dp);
    }

//tabulation
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        //base case already default
        for(int ind=n-1;ind>=0;ind--){
            for(int cap=1;cap<=2;cap++){
                dp[ind][0][cap]=max(prices[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
                dp[ind][1][cap]=max(-prices[ind]+dp[ind+1][0][cap],dp[ind+1][1][cap]);
            }
        }
        return dp[0][1][2];
}
//space optimize
int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> prev(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));
        //base case already default
        for(int ind=n-1;ind>=0;ind--){
            for(int cap=1;cap<=2;cap++){
                curr[0][cap]=max(prices[ind]+prev[1][cap-1],prev[0][cap]);
                curr[1][cap]=max(-prices[ind]+prev[0][cap],prev[1][cap]);
            }
            prev=curr;
        }
        return curr[1][2];

        
        
    }