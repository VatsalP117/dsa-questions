//link: https://leetcode.com/problems/word-break/submissions/
class Solution {
public:
    bool solve(int i,string &s,unordered_set<string> &words,vector<int> &dp){
        if(i==s.size()) return true;
        if(dp[i]!=-1) return dp[i];
        string temp="";
        bool ans=false;
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(words.find(temp)!=words.end()){
                ans=ans||solve(j+1,s,words,dp);
            }
        }
        return dp[i]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for(auto it:wordDict){
            words.insert(it);
        }
        vector<int> dp(s.size(),-1);
        return solve(0,s,words,dp);
    }
};