//link: https://leetcode.com/problems/longest-valid-parentheses/submissions/

//my solution (kaam chalau hai only beats 6% lmao)
//iska stack solution bhi in stacks folder must check it performs much better
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        vector<int> dp(n,0);
        int res=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                dp[i]=0;
                continue;
            }
            //yaha hai matlab to closing bracket hai
            if(i>=1 && s[i-1]=='('){
                //means we have got atleast a length of 2
                dp[i]=2;
                if(i>=2){
                    dp[i]+=dp[i-2];
                }
            }
            else if(i>=1 && s[i-1]==')' && dp[i-1]!=0){
                //means we can try to extend this maybe??
                int count=dp[i-1]/2;
                cout<<i<<" "<<s[i]<<dp[i-1]<<endl;
                //itne opening bracket ignore maarne hai
                for(int ind=i-1;ind>=0;ind--){
                    
                    if(s[ind]=='('){
                        count--;
                        if(count==0){
                            if(ind-1>=0 && s[ind-1]=='('){
                                dp[i]+=dp[i-1]+2;
                                if(ind-2>=0){
                                    dp[i]+=dp[ind-2];
                                }
                            }
                            break;
                        }
                    }
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};