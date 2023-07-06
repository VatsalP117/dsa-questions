void f(int ind,vector<int> &nums,vector<int> &res,vector<vector<int>> &ans){
        //base case
        if(ind<0){
            ans.push_back(res);
            return;
        }
        //
        for(int i=0;i<nums.size();i++){
            if(res[i]==1e8){
                res[i]=nums[ind];
                f(ind-1,nums,res,ans);
                //backtracking now
                res[i]=1e8;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,1e8);
        vector<vector<int>> ans;
        f(n-1,nums,res,ans);
        return ans;
    }