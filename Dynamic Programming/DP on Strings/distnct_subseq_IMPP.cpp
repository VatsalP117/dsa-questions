//memoization
int f(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        //optimization (not needed but makes very fast)
        if(i<j) return 0;
        //since s mai utne characters hi nahi jitne t mai hai abhi
        //base case

        if(j<0) return 1; //matched all characters we wanted
        if(j>=0 && i<0) return 0; //characters still left to match but s1 got exhausted
        if(dp[i][j]!=-1) return dp[i][j];
        //matches
        if(s[i]==t[j]){
            //match so we can take it or wait for another match later
            return dp[i][j]=f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
        }
        else{
            return dp[i][j]=f(i-1,j,s,t,dp);
        }
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
    }


//tabulation
#include <bits/stdc++.h> 
int subsequenceCounting(string &s, string &t, int lt, int ls) {
    // Write your code here.
         int n=s.size();
        int m=t.size();
        int mod=(1e9) + 7;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //base case
        //j<0(j=-1) pe 1 means j=0 pe we need 1
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        //base case 2 : i=0 (i=-1 og) pe zero
        for(int j=1;j<=m;j++){
            dp[0][j]=0;
        }

        //convert to for loops
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
                }
                else{
                    dp[i][j]=dp[i-1][j]%mod;
                }
            }
        }
        return dp[n][m]%mod;
} 