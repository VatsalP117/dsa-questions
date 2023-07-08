//memoization
  int f(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        //base case
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];

        //f(i,j)=lcs of s1[0..i] and s2[0..j]
        if(s1[i]==s2[j]){
            return dp[i][j]=1+f(i-1,j-1,s1,s2,dp);
        }
        else{
            return dp[i][j]=max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
        }
    }
//tabulation
int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //tabulation
        //since bases are i<0 and j<0 lets shift the indexes to the right by 1
        //the -1 is moved to 0, 0 is moved to 1 and so on
        //therefore for all cases where i=0 or j=0 dp[i][j]=0 (base case)
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //strings are still in 0-based indexing remember
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
//space optimization
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        //how to convert base case: shift indexes by 1
        //so -1 is now =0
        //so base case is basically dp[0][all]=dp[all][0]=0 (already covered inby default)
        for(int i=1;i<=n;i++){
            curr[0]=0;
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[m];
    }