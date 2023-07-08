//yaha bhi input is vector of int not string (hackerrank)
vector<int> longestCommonSubsequence(vector<int> s, vector<int> t) {
                int n=s.size();
                int m=t.size();
                vector<vector<int>> dp(n+1,vector<int>(m+1,0));
                //base case already covered =0 by default
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++){
                        if(s[i-1]==t[j-1]){
                            dp[i][j]=1+dp[i-1][j-1];
                        }
                        else{
                            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                        }
                    }
                }
                //dp matrix now ready
                vector<int> ans;
                
                int i=n;
                int j=m;
                while(i>0 && j>0){
                    if(s[i-1]==t[j-1]){
                        ans.push_back(s[i-1]);
                        i--;
                        j--;
                    }
                    else{
                        //not match so go where there is a match
                        if(dp[i-1][j]>=dp[i][j-1]){
                            i--;
                        }
                        else{
                            j--;
                        }
                    }
                }        
                 
                reverse(ans.begin(),ans.end());
                return ans;
}
