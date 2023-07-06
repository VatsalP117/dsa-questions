//return all subsets adding up to a target value
//can pick one element unlimited number of times
class Solution {
public:
    void f(int ind,int target,vector<int> &candidates,vector<int> &res,vector<vector<int>> &ans){
        //base case
        if(ind<0){
            if(target==0){
                ans.push_back(res);
                
            }
            return;
        }
        //take
            
            res.push_back(candidates[ind]);
            if(candidates[ind]<=target){
                f(ind,target-candidates[ind],candidates,res,ans);
            }
            
     
            //not take
            res.pop_back();
            
            f(ind-1,target,candidates,res,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        int n=candidates.size();
        f(n-1,target,candidates,res,ans);
        return ans;
    }
};