//link: https://leetcode.com/problems/missing-number/

//Optimal solution : (not using cycle sort)
   int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int expected_sum=0;
        int actual_sum=0;
       for(int i=0;i<=n;i++) expected_sum+=i;
       for(int i=0;i<nums.size();i++){
           actual_sum+=nums[i];
       }
        return expected_sum-actual_sum;
    }

//Solution using cycle sort
   int missingNumber(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        //numbers will be in the range [0,N] so total N+1 numbers
        //sahi se sort kiya to correct index for every value = value
        //bas jo N hai vo fit nahi hoga to vo dikh jaye to lite le lena
        while(i<n){
            int correctIndex=arr[i];
            if(i==correctIndex || arr[i]==n){
                i++;
            }
            else{
                swap(arr[i],arr[correctIndex]);
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]!=i) return i;
        }
        return n;
    }