//memoization
bool f(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        //base case
        if(i<0 && j<0) return true;
        if(j>=0 && i<0) return false;
        if(j<0 && i>=0){
            
            for(int k=0;k<=i;k++){
                if(s[k]!='*'){
                    
                    return false;
                }
            }
            return true;;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        //matches
        if(s[i]==t[j] || s[i]=='?'){
            return dp[i][j]=f(i-1,j-1,s,t,dp);
        }
        else{
            //no match
            if(s[i]!='*'){
                return dp[i][j]=false;
            }
            else{
                return dp[i][j]=f(i-1,j,s,t,dp)||f(i,j-1,s,t,dp);
            }
        }

    }
    bool isMatch(string t, string s) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
    }

//tabulation
    bool isMatch(string t, string s) {
        int n=s.size();
        int m=t.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        
        //base case1 (i==j==-1) means (i==j==0 here)
        dp[0][0]=true;

        //base case2 (already covered but just to show)
        // for(int j=1;j<=m;j++){
        //     dp[0][j]=false;
        // }

        //base case 3
        for(int i=1;i<=n;i++){
            dp[i][0]=true;
            for(int k=1;k<=i;k++){
                if(s[k-1]!='*'){
                    dp[i][0]=false;
                    break;
                }
            }
        }

        //convert to for-loops
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1] || s[i-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(s[i-1]=='*'){
                    dp[i][j]=dp[i-1][j]||dp[i][j-1];
                }
            }
        }
        return dp[n][m];

        
    }