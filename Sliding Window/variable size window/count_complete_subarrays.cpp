//link: https://leetcode.com/contest/weekly-contest-356/problems/count-complete-subarrays-in-an-array/
Question: 
You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.

Code: 
Logic behind res+=n-j
tereko ek subarray mil gay jo confition staisfy kar raha h 
an isk subarray ko aage expand karenge to vo saare subarray bhi satisyf karenge hi na 
ab expand kitna kar sakte hai? jitne piche elements hai

int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        int count_distinct=s.size();
        int total=(n*(n+1))/2;
        int i=0;
        int j=0;
        int count=0;
        int res=0;
        unordered_map<int,int> um;
        while(j<n){
            um[nums[j]]++;
            if(um[nums[j]]==1){
                count++;
            }
            if(count==count_distinct){
                while(count==count_distinct){
                    res+=n-j;
                    um[nums[i]]--;
                    if(um[nums[i]]==0)count--;
                    i++;
                }
            }
            j++;
        }
        return res;
    }