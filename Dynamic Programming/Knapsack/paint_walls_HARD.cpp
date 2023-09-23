//leetcode 2742: painting the walls

class Solution {
public:
    int dp[501][501];//stores cost to paint all wails till the index i
    int solve(int ind,int toPaint,vector<int>& cost, vector<int>& time){
        if(toPaint<=0) return 0;
        if(ind>=cost.size()) return 1e9; //means we completed the array par walls bach gayi for bhi
        if(dp[ind][toPaint]!=-1) return dp[ind][toPaint];
        //now we have 2 options : either hire a paid fella for this wall or not
        //if we do, we have time of that paid painter number of walls jo free wala kar dega
        int ans=solve(ind+1,toPaint-1-time[ind],cost,time)+cost[ind];
        //or not paint this and hope aage koi paid painter lega vo time mai free wala hume nipta dega
        ans=min(ans,solve(ind+1,toPaint,cost,time));
        return dp[ind][toPaint]=ans;
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        //the problem reduces by a great extent when you real n= number of walls to paint initialize
        //our goal is just to bring this to 0 bas
        memset(dp,-1,sizeof dp);
        int n=cost.size();
        return solve(0,n,cost,time);
    }
};