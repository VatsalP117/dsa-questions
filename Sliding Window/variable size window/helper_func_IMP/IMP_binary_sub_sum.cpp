//link: https://leetcode.com/problems/binary-subarrays-with-sum/description/
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

Code:

class Solution {
public:
    int helper(vector<int>& a, int k){
        //basically number of subarrays where sum<=k
        int n=a.size();
    int i=0;
    int j=0;
    long long sum=0;
    int res=0;
    while(j<n){
        sum+=a[j];
        //approach: always stay in the range<k and try to reach k
        //if you overshoot, remove elements by i++ and again try to reach in <=k range
        //sum se aage chale gaye to vapas aa jao
        //vapas kaise? aage ke elemnts hatake
        if(sum>k){
            while(i<=j && sum>k){
            sum=sum-a[i];
            i++;
            }
        }
        if(sum<=k){

            res+=j-i+1;
        }
        //j to humesha badhega
        j++;
        
    }
    return res;
    }
    int numSubarraysWithSum(vector<int>& a, int k) {
            return helper(a,k)-helper(a,k-1);
    }
};