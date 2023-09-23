//leetcode 5
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
         //idea is (i..j) is palindrome if
        //1. s[i]==s[j]
        //2 (i+1,j-1) is a palindrome
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        //dp[i][j] shows if s[i..j] is a palindrome or not
        int res=1;
        string ans=s.substr(0,1);
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            //since every single character is a palindrome
            if(i<n-1 && s[i]==s[i+1]){
                 dp[i][i+1]=true;
                 res=2;
                 ans=s.substr(i,2);
            }
        }
        
       //length 1 and 2 ka maamla to sorted hai
       //to find length 3 ka decision apne ko saari length 1 and 2 ka pata hona chaiye
       //length 4 ka pata karne saare 1,2,3 ka pata hona chaiye
        for(int gap=2;gap<n;gap++){
            for(int i=0;i<n;i++){
                int j=i+gap;
                if(j>=n) break;
                if(s[i]==s[j] && dp[i+1][j-1]==true){
                    dp[i][j]=true;
                    if(j-i+1>res){
                        res=j-i+1;
                        ans=s.substr(i,j-i+1);
                    }
                }
            }
        }
        cout<<res<<endl;
        return ans;
    }
};