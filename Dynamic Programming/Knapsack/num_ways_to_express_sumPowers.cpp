//link:https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/description/

// Given two positive integers n and x.

// Return the number of ways n can be expressed as the sum of the xth power of unique positive integers, 
// in other words, the number of sets of unique integers [n1, n2, ..., nk] where n = n1x + n2x + ... + nkx.

// Since the result can be very large, return it modulo 109 + 7.

// For example, if n = 160 and x = 3, one way to express n is n = 23 + 33 + 53.

    int solve(int ind,int target,vector<long long> &arr,vector<vector<int>> &dp){
        //base lite
        int mod=1e9+7;
        if(target==0) return 1;
        if(ind<0){
            if(target==0) return 1;
            else return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int notTake=solve(ind-1,target,arr,dp)%mod;
        int take=0;
        if(arr[ind]<=target){
            take=solve(ind-1,target-arr[ind],arr,dp)%mod;
        }
        return dp[ind][target]=(take+notTake)%mod;
    }
    int numberOfWays(int n, int x) {
        //n ko express karna in terms of numbers raised to powers of x
        //which numbers are possible? obivosly the number less than n/2
        vector<long long> arr;
        for(int i=1;i<=n;i++){
            if(pow(i,x)<=n){
                //tabhi it can be our candidate
                arr.push_back((long long)pow(i,x));
            }
        }
        vector<vector<int>> dp(arr.size(),vector<int>(n+1,-1));
        return solve(arr.size()-1,n,arr,dp);
    }