//link: https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/submissions/
// You are given a 0-indexed array nums and a non-negative integer k.

// In one operation, you can do the following:

// Choose an index i that hasn't been chosen before from the range [0, nums.length - 1].
// Replace nums[i] with any integer from the range [nums[i] - k, nums[i] + k].
// The beauty of the array is the length of the longest subsequence consisting of equal elements.

// Return the maximum possible beauty of the array nums after applying the operation any number of times.

// Note that you can apply the operation to each index only once.


// Algo in one line (great interesting approach):
// All elements can be equal if the 
// "max of range of minimum element is greater than equal to min of range of maxium element".

// for this we would need min and max till every index so sorting and then sliding window
int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=0;
        int res=0;
        while(i<n && j<n){
            //nums[i] points to current min and nums[j] to current max
            if(nums[i]+k<nums[j]-k){
                while(nums[i]+k<nums[j]-k){
                    i++;
                }
            }
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }