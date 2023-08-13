//link: https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1

//brute force
Try to make all pairs of two such that they are the last 2 elements of an AP, then go back and see which elements can 
join and become a part of that AP (array is sorted)
(tle after 214/220 cases tho)

    int solve(int ind,int arr[],int prev,int d){
        //ind is basically jaha se checking shuru karni hai
        int res=0;
        while(ind>=0){
            if(prev-arr[ind]==d){
                res++;
                prev=arr[ind];
            }
            ind--;
        }
        return res;
    }
    int lengthOfLongestAP(int arr[], int n) {
        // code here
        if(n<=2){
            return n;
        }
        //now make pairs of 2 and consider them as last 2 elements of an AP
        //then check which elements can join this ap
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                //the last 2 numbers are arr[i] and arr[j]
                int common_d=arr[j]-arr[i];
                int num_ele=solve(i-1,arr,arr[i],common_d);
                //num of element which can join our AP
                maxi=max(maxi,2+num_ele);
                
            }
        }
        return maxi;
    }
//recursive +memoization ( fir bhi saare pass nahi hue)

dp[ind][diff] => length of longest AP till ind index with common difference=diff
int solve(int ind,int diff,int arr[],vector<vector<int>> &dp){
        if(ind<0) return 0;
        if(dp[ind][diff]!=-1) return dp[ind][diff];
        int ans=0;
        for(int j=ind-1;j>=0;j--){
            if(arr[ind]-arr[j]==diff){
                ans=max(ans,1+solve(j,diff,arr,dp));
            }
        }
        return dp[ind][diff]=ans;
    }
    int lengthOfLongestAP(int arr[], int n) {
        // code here
        if(n<=2){
            return n;
        }
        int max_diff=arr[n-1]-arr[0];
        vector<vector<int>> dp(n+1,vector<int>(max_diff+1,-1));
        //now make pairs of 2 and consider them as last 2 elements of an AP
        //then check which elements can join this ap
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                //the last 2 numbers are arr[i] and arr[j]
               
                int num_ele=solve(i,arr[j]-arr[i],arr,dp);
                maxi=max(maxi,2+num_ele);
                
            }
        }
        return maxi;
    }

//optimal dp passing all cases

    int lengthOfLongestAP(int arr[], int n) {
        // code here
        if(n<=2) return n;
        int max_diff=arr[n-1]-arr[0];//since sorted varna we can use just use an unordered map like:
        //vector<unordered_map<int, int>> dp(n); (will work the same) for every index store {diff,longest_length}
        vector<vector<int>> dp(n+1,vector<int>(max_diff+1,1));
        //actually use map if unsorted coz negative difference bhi store kar sakte ho to better
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                //arr[i] last ele, arr[j] 2nd last of our AP
                int diff=arr[i]-arr[j];
                int count=1;//abhi to arr[i] hi hai ap mai
                if(dp[j][diff]!=-1){
                    count+=dp[j][diff];
                }
                //count basically length of longest ap ending at j with our diff
                dp[i][diff]=count;
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
        
    }

    //unordered_map
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int res=0;
        vector<unordered_map<int,int>> dp(n);
        //basically for every index, difference and lenght of ap store karne
        for(int i=1;i<n;i++){
            
            for(int j=0;j<i;j++){
                int count=1;//vo element khud i.e nums[i]
                int diff=nums[i]-nums[j];
                if(dp[j].find(diff)!=dp[j].end()){
                    count=dp[j][diff];
                    //agar j pehle si kisi mai hai vo
                }
                dp[i][diff]=count+1; //ab yaha j bhale pehle se kisi mai na ho, sirf akele to aayega (aur agar uska count aa gya to i)
                res=max(res,dp[i][diff]);
            }
        }   
        return res;
    }