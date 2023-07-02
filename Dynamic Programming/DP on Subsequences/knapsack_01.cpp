//robber stealing with a fix bag weight

//memoization
    int f(int ind,int W,int wt[],int val[],vector<vector<int>> &dp){
        //base case
        if(W==0) return 0;
        if(ind==0) {
            if(wt[0]<=W) return val[0];
            else return 0;
        }
        if(dp[ind][W]!=-1) return dp[ind][W];
        //
        int notTake=0+f(ind-1,W,wt,val,dp);
        int take=0;
        if(wt[ind]<=W) take=val[ind]+f(ind-1,W-wt[ind],wt,val,dp);
        return dp[ind][W]=max(take,notTake);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int>(W+1,-1));
       return f(n-1,W,wt,val,dp);
    }

//tabulation
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int>(W+1,0));
       for(int ww=wt[0];ww<=W;ww++){
           dp[0][ww]=val[0];
       }
       
       //convert to for loops
       for(int ind=1;ind<n;ind++){
           for(int ww=1;ww<=W;ww++){
                int notTake=0+dp[ind-1][ww];
                int take=0;
                if(wt[ind]<=ww) take=val[ind]+dp[ind-1][ww-wt[ind]];
                dp[ind][ww]=max(take,notTake);
           }
       }
       return dp[n-1][W];
    }