int f(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){

        //function find length of longest common subsequence of two strings
        //if you pass it s1 and reverse(s1) you get length of longest palindromic subsequence


        //base case
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        //match
        if(s1[i]==s2[j]){
            return dp[i][j]=1+f(i-1,j-1,s1,s2,dp);
        }
        else{
            return dp[i][j]=max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
        }
    }
    int minInsertions(string s) {
        int n=s.size();
        string t = string(s.rbegin(), s.rend());
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int lengthOfPalindromicSub=f(n-1,n-1,s,t,dp);
        return n-lengthOfPalindromicSub;
    }