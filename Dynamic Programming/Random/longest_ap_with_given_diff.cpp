//link: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

//the approach of longest ap (gives tle)
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        vector<int> dp(n+1,1);
        //basically stores length of longest ap with diff till each index
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                //i,j will give last,2nd last elements of our ap
                int diff=arr[i]-arr[j];
                if(diff==difference){
                    dp[i]=max(dp[i],1+dp[j]);
                    ans=max(ans,dp[i]);
                }
                
            }
        }
        return ans;
    }

//optimal
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        // vector<int> dp(n+1,1);
        unordered_map<int,int> dp;//value of some element in arr,length of longest ap till that
        int ans=0;
        for(int i=0;i<n;i++){
            int candidate=arr[i]-difference;
            //ye ap ka 2nd last element ho sakta hai
            int count=1;
            if(dp.find(candidate)!=dp.end()){
                count+=dp[candidate];
            }
            dp[arr[i]]=count;
            ans=max(ans,count);
            //iske saath apne join ho sakte hai na dost

        }
        return ans;
    }