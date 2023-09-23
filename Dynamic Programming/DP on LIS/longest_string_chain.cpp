//leetcode 1048

class Solution {
public:
    bool canJoin(string &shorter,string &longer){
        int n=longer.size();
        int m=shorter.size();
        if(n<=m) return false;
        if(n-m!=1) return false;
        //yaha tk aa gaye means longer is just 1 more i length than shorter
        //ab dono ko join karne shorter ke sab characters milne chaiye in longer wahi order mai
        //order bhi wahi hona chaiye bas bich mai koi ek gandu alag aa gya to chalega
        int i=0;//for longer
        int j=0;//for shorter
        while(i<n && j<m){
            if(longer[i]==shorter[j]){
                i++;
                j++;
            }
            else{
                //means ye ho sakta vo char jo shayad add karna pade to isko skip
                i++;
            }
        }
        if(j==m){
            //means saare ka match mil gya except one
            return true;
        }
        return false;
    }
    static bool cmp(string &s,string &t){
        return s.size()<t.size();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),cmp);
        vector<int> dp(n,0);//dp[i ]stores length of longest valid chain till index i
        int res=0;
        for(int i=0;i<n;i++){
            dp[i]=1;;//ye khud akele to bichara aa hi jayega na
            for(int j=0;j<i;j++){
                if(canJoin(words[j],words[i])){
                    dp[i]=max(dp[i],1+dp[j]);
                }
                
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};