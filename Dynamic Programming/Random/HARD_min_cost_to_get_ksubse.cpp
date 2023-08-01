//asked in gfg contest (i did this on my own which i didnt expect so cheers!)

Question:
ou are given two strings A of length N and B of length M. 
These strings contain lowercase English alphabets. 
You are also given an integer K. You can change the character of x string A to any other characters y.
 The cost of this conversion is abs( ASCII(x)- ASCII(y) ). 
 Find the minimum cost required such that the length of the longest common subsequence (LCS) 
 of A and B is at least K.

 Solution:
 int solve(int i,int j,int k,string &A,string &B,vector<vector<vector<int>>> &dp){
        //base
        if(k==0) return 0;
        if(i<0 || j<0){
            if(k==0) return 0;
            else return 1e8;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        //match
        if(A[i]==B[j]){
            //no bt lessgo
            return dp[i][j][k]=solve(i-1,j-1,k-1,A,B,dp);
        }
        else{
            //you either replace the char in A to match or let it go
            return dp[i][j][k]=min(abs(A[i]-B[j])+solve(i-1,j-1,k-1,A,B,dp),min(solve(i-1,j,k,A,B,dp),solve(i,j-1,k,A,B,dp)));
        }
    }
    int generateSub(string A, string B, int N, int M,
                    int K) {
        //Code Here
        
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(M,vector<int>(K+1,-1)));
        return solve(N-1,M-1,K,A,B,dp);
    }