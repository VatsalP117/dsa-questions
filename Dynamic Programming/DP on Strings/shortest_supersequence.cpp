    string shortestCommonSupersequence(string s1, string s2) {
        //tabulation code for LCS of two strings
        //in supersequence, we will take every character from s1 and s2 but LCS usme 2 baar aa jayega na
        //so length of supersequence=n+m-LCS

        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                cout<<dp[i][j]<<" ";
            }
        cout<<endl;
        }
        int i=n;
        int j=m;
        string res="";
        while(i>=1 && j>=1){
            if(s1[i-1]!=s2[j-1]){
                if(dp[i-1][j]>=dp[i][j-1]){
                    res+=(s1[i-1]);
                    i--;
                }
                else{
                   res+=(s2[j-1]);
                   j--; 
                }
            }
            else{
                res+=(s1[i-1]);
                i--;
                j--;
            }
        }
        while(i>=1){
            res+=s1[i-1];
            i--;
        }
        while(j>=1){
            res+=s2[j-1];
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }