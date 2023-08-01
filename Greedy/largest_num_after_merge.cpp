//https://leetcode.com/problems/largest-element-in-an-array-after-merge-operations/

// You are given a 0-indexed array nums consisting of positive integers.

// You can do the following operation on the array any number of times:

// Choose an integer i such that 0 <= i < nums.length - 1 and nums[i] <= nums[i + 1]. 
// Replace the element nums[i + 1] with nums[i] + nums[i + 1] and delete the element nums[i] from the array.
// Return the value of the largest element that you can possibly obtain in the final array.


//Greedy
// The greedy approach here is based on the observation that, in order to maximize the final value,
// we should try to combine smaller elements as much as possible. 
// By doing so, we can create larger elements that can later be combined with even larger elements.
// The algorithm processes the array from right to left. When it encounters an element that is greater than the current
// running sum (sum), it decides to start a new group from that element because combining it with the 
// previous element(s) will violate the non-decreasing order. On the other hand, 
// if the element is less than or equal to the current running sum, it can be safely combined with the next element
// (which is sum). This way, the algorithm ensures that it combines adjacent elements optimally,
//  leading to the maximum possible value in the final array.
    long long maxArrayValue(vector<int>& nums) {
          long long sum = 0;
        for(int i= nums.size()-1 ; i>=0 ; i--){
            //the number of left is less than curr-sum on right so isko merge karke sum aur bada ho jayega
            //sum basically stores curr_max number after merging whatever possible
            if(nums[i] <= sum) sum += nums[i];
            //now we have a number of left> curr-max
            //ye merge bhi nahi hoga aur iske hote hue apna curr_max ans bhi nahi ban sakta to usko jaane do
            else sum = nums[i];
        }
        return sum;
    }