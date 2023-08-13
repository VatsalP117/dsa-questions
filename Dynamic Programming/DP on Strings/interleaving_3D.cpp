//link: https://leetcode.com/problems/interleaving-string/submissions/
class Solution {
public:
    bool isEqual(string s,string t,int ind1,int ind2){
        int n=s.size();
        int m=t.size();
        if(ind1!=ind2) return false;
        while(ind1>=0 && ind2>=0){
            if(s[ind1]!=t[ind2]) return false;
            ind1--;
            ind2--;
        }
        return true;
    }
    bool solve(int i,int j,int k,string &s1, string &s2, string &s3,vector<vector<vector<int>>> &dp){
        //base case
        
        if(i<0 && j<0 && k<0) return true;
        if(k<0) return false;
        if(i<0 && j>=0){
            if(isEqual(s2,s3,j,k)) return true;
            else return false;
        }
        if(i>=0 && j<0){
            if(isEqual(s1,s3,i,k)) return true;
            else return false;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        if(s1[i]!=s3[k] && s2[j]!=s3[k]) return dp[i][j][k]=false;
        bool ans=false;
        if(s1[i]==s3[k]){
            ans=ans||solve(i-1,j,k-1,s1,s2,s3,dp);
        }
        if(s2[j]==s3[k]){
            ans=ans||solve(i,j-1,k-1,s1,s2,s3,dp);
        }
        return dp[i][j][k]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int p=s3.size();
        if(n+m!=p) return false;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(p,-1)));
        return solve(n-1,m-1,p-1,s1,s2,s3,dp);
    }
};