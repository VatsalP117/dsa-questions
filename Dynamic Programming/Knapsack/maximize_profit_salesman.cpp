//leetcode 2830: Maximising profit as salesman

class Solution {
public:
    const int INF=(int)1e9; 
    static bool cmp(vector<int> &offer1,vector<int>& offer2){
        return offer1[0]<offer2[0];
    }
    int solve(int ind,vector<vector<int>>& offers,vector<int> &dp){
        if(ind>=offers.size()){
            return 0;
            //we have decided on all offers :)
        }
        if(dp[ind]!=-1) return dp[ind];
        //now we have 2 options take this offers or not take it
        //if we take it,next konsi offer consider kar sakte? jiska start house number > apne offer ka end number
        vector<int> v={offers[ind][1],INF,INF};
        int nextIndex=upper_bound(offers.begin(),offers.end(),v)-offers.begin();
        //nextIndex is the index of next offer jisme start house > apna en dhouse
        int ans=solve(nextIndex,offers,dp)+offers[ind][2];
        ans=max(ans,solve(ind+1,offers,dp));
        return dp[ind]=ans;
        
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end(),cmp);//sorted by start number of houses
        vector<int> dp(offers.size(),-1);
        return solve(0,offers,dp);
        
    }
};