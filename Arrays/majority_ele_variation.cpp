//https://leetcode.com/problems/minimum-index-of-a-valid-split/description/

// An element x of an integer array arr of length m is dominant if freq(x) * 2 > m, where freq(x) is the number of occurrences of x in arr. Note that this definition implies that arr can have at most one dominant element.

// You are given a 0-indexed integer array nums of length n with one dominant element.

// You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:

// 0 <= i < n - 1
// nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
// Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.

// Return the minimum index of a valid split. If no valid split exists, return -1.

//INshort, vo inex batao jaha se arrayy ko split kare s.t both new arrays have the same dominant element (>size/2 freq)

    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        int res=-1;
        int count=0;
        //first find majority element 
        for(int i=0;i<n;i++){
            if(count==0){
                res=nums[i];
                
            }
           if(nums[i]==res){
               count++;
           }
            else{
                count--;
            }
        }
        int tot_count=0;
        //res now stores the most dominant element
        //if we are at index i, lets split as 0..i-1 and i...n-1
         for(int i=0;i<n;i++){
            if(nums[i]==res)tot_count++;
         }
         
        int curr_count=0;
        if(nums[0]==res) curr_count++;
        for(int i=1;i<n;i++){
            
            int left_size=i;
            int right_size=n-i;
            if(curr_count>(left_size/2) && (tot_count-curr_count>(right_size/2))){
                return i-1;
            }
            if(nums[i]==res) curr_count++;
        }
        return -1;
    }