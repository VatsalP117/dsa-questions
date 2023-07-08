//memoization
int f(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        //to convert s1 into s2
        //eg: s1=horse and s2=ros so gotta convert horse to ros
        //base case
        if(j<0) return i+1; //if to convert it to empty str, need to delete etire string s1
        if(i<0) return j+1; //if to convert empty str to s2, need to add all chars of string s2

        //memoization
        if(dp[i][j]!=-1) return dp[i][j];

        //not matched
        if(s[i]!=t[j]){
            //we have 3 options: replace that char in s1, delete it, or insert it in front of it(respectivly)
            return dp[i][j]=1+min(f(i-1,j-1,s,t,dp),min(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp)));
        }
        else{
            return dp[i][j]=f(i-1,j-1,s,t,dp);
        }
    }
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s1,s2,dp);
    }

//tabulation
int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //base case
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }
        //now convert to for-loops
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]!=s2[j-1]){
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
                else{
                    dp[i][j]=dp[i-1][j-1];
                }
            }
        }
        return dp[n][m];
    }