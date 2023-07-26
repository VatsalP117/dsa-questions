class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,0);
        if(s[0]!='0') dp[0]=1;
        else return 0;
        //since only character hai to only one way to decode and if=0, not in decoding posibility
        if(n==1) return dp[0];
      
        //now second base case
        if(s[1]!='0') dp[1]++;
        if(stoi(s.substr(0,2))>=10 && stoi(s.substr(0,2))<=26){
            //basically first characters can be decoded together
            dp[1]++;
        }
        if(dp[1]==0) return 0;
        //now tabulation
        for(int i=2;i<n;i++){
            int oneDigit=stoi(s.substr(i,1));//current char
            int twoDigits=stoi(s.substr(i-1,2));//last and current char
            if(oneDigit>=1){
                dp[i]+=dp[i-1];
            }
            if(twoDigits>=10 && twoDigits<=26){
                dp[i]+=dp[i-2];
            }
            if(dp[i]==0) return 0;
        }
        return dp[n-1];
    }
};