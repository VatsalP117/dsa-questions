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
    int minDistance(string word1, string word2) {
        //to convert word1 to word2
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int common_length=f(n-1,m-1,word1,word2,dp);
        int numDelete=(n-common_length);
        int numAdd=(m-common_length);
        return numAdd+numDelete;
    }