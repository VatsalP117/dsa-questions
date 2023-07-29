//linK:https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/
class Solution {
public:
        int f(int ind, int sum, int k,vector<vector<int>> &dp) {
        // ind is basically which dice we currently are on
        // stop if we reach ind==0
        int mod=1e9+7;
        if (ind <= 0) {
            if (sum == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        // Check if the target sum becomes negative, then return 0
        if (sum < 0) {
            return 0;
        }
        // for the current dice we can have any value from 1 to k
        long res = 0;
        for (int i = 1; i <= k; i++) {
            if (i <= sum) {
                res += f(ind - 1, sum - i, k,dp)%mod;
            }
        }
        return dp[ind][sum]=res%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        //k= number of faces
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return f(n,target,k,dp);

    }
};


//Tabulation 
    int numRollsToTarget(int n, int k, int target) {
        //k= number of faces
        int mod=1e9+7;
        vector<vector<long>> dp(n+1,vector<long>(max(k+1,target+1),0));
        //dp[ind][sum] stores number of ways to get required sum using ind number of dices dices
        for(int i=1;i<=k;i++){
            dp[1][i]=1;
            //since only 1 way to achieve this with one dice
        }
        //now lets see the cases for more than 1 dice
        for(int ind=2;ind<=n;ind++){
            for(int sum=1;sum<=target;sum++){
                for (int i = 1; i <= k; i++) {
                    if (i <= sum) {
                        dp[ind][sum] += dp[ind - 1][sum - i]%mod;
                    }
                }
            }
        }
        return dp[n][target]%mod;

    }