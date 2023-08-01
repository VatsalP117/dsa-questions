//link: https://www.codingninjas.com/studio/problems/count-subsets-with-sum-k_3952532?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1
int solve(int ind,int sum,vector<int> &nums,vector<vector<int>> &dp){
        if(ind<0){
            if(sum==0){
                return 1;
            }
            else return 0;
        }
		if(dp[ind][sum]!=-1) return dp[ind][sum];
        //not take
		int mod=1e9+7;
        int notTake=solve(ind-1,sum,nums,dp);
        //take
        int take=0;
        if(nums[ind]<=sum){
            take=solve(ind-1,sum-nums[ind],nums,dp);
        }
        return dp[ind][sum]=(take+notTake)%mod;
    }
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n=arr.size();
	vector<vector<int>> dp(n,vector<int>(k+1,-1));
	return solve(n-1,k,arr,dp);
}
