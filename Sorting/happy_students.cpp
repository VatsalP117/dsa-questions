//leetcode 2860
class Solution {
public:
    int countWays(vector<int>& nums) {
        int n=nums.size();
        //to keep track of sabsi wishes we need to sort this array
        sort(nums.begin(),nums.end());
        //a student if happy is any of the 2 condition are met:
        //1: selected && selected students > nums[i]
        //2: not selected && selected students <nums[i]
        int num_selected=0;
        int res=0;// stores number of ways
        if(0<nums[0]){
            //means we selected no one
            //if first student is happy with it then everyone is
            //since nums[0] is smallest of all in sorted array
            res++;
        }
        if(n>nums[n-1]){
            //all are selected
            //again same logic as no one selected
            res++;
        }
        for(int i=0;i<n-1;i++){
            num_selected++;
            if(num_selected>nums[i] && num_selected<nums[i+1]){
                //we assumed everyone from 0..i is selected
                //ans everyone from i+1..n-1 is not
                //so if num_selected<nums[i+1] aage walo se bhi chota hi hoga 
                res++;
            }
        }
        return res;
    }
};