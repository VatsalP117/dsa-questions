//link:https://leetcode.com/problems/palindrome-partitioning-ii/

Memoization Code (gives TLE)


class Solution {
public:
    bool isPalindrome(string &s,int i,int j){
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    int solve(string &s,int i,int j,vector<vector<int>> &dp){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(isPalindrome(s,i,j)) return 0;
        
        int ans=j-i;
        for(int k=i;k<=j-1;k++){
            int temp_ans=solve(s,i,k,dp)+solve(s,k+1,j,dp)+1;
            ans=min(ans,temp_ans);
        }
        return dp[i][j]=ans;
    }
    int minCut(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(s,0,n-1,dp);
    }
};


Optimization : pre-compute all palindrome substrings so isPalindrome check happens in O(1) but TLE fir bhi aayega

class Solution {
public:
 
    int solve(string &s,int i,int j,vector<vector<int>> &dp,vector<vector<bool>> &isPalindrome){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(isPalindrome[i][j]) return 0;
        
        int ans=j-i;
        for(int k=i;k<=j-1;k++){
            int temp_ans=solve(s,i,k,dp,isPalindrome)+solve(s,k+1,j,dp,isPalindrome)+1;
            ans=min(ans,temp_ans);
        }
        return dp[i][j]=ans;
    }
    int minCut(string s) {
        int n=s.size();
         vector<vector<bool>> isPalindrome(n , vector<bool> (n , false));
        for(int i=n-1 ; i>=0 ; i--){
            for(int j=i ; j<n ; j++){
                if(s[i] == s[j]){
                    if(j-i <= 2){ // substring of length 1 and 2
                        isPalindrome[i][j] = true;
                    }else{
                        isPalindrome[i][j] = isPalindrome[i+1][j-1];
                    }
                }
            }
    }
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(s,0,n-1,dp,isPalindrome);
    }
};