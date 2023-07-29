//link: https://www.interviewbit.com/problems/dice-rolls/
Can roll a standard 6-faced dice any number of times 
just tell the number of ways to achieve target sum 


int Solution::solve(int A) {
    int mod = 1000000007;
    vector<long>dp(A+1, 0);
    for(int i=1; i<=6; i++) if (i<=A) dp[i]=1;

    for(int i=1 ; i<=A; i++)
    {

        for(int j=1;j<=6;j++){
            if(i-j>=0){
                dp[i]+=dp[i-j]%mod;
            }
        }
    }
    return dp[A]%mod;
}