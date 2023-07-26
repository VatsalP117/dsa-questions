//link:https://leetcode.com/problems/count-number-of-nice-subarrays/submissions/
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.


class Solution {
public:
    bool isOdd(int num){
	return num%2==1;
}
    int helper(vector<int>& arr, int k){
        int res=0;
	int count=0;
	int i=0;
	int j=0;
	int n=arr.size();
	while(j<n){
		//calculations as usual pehle hi
		if(isOdd(arr[j])){
			count++;
		}
		//if overshoots condition then resolve the situation
		if(count>k){
			while(count>k){
				if(isOdd(arr[i])){
					count--;
				}
				i++;
			}
		}
		//now count num of subarrays
		if(count<=k){
			res+=j-i+1;
		}
		j++;
	}
	return res;
    }
		int numberOfSubarrays(vector<int>& arr, int k) {
	// Write your code here
    return helper(arr,k)-helper(arr,k-1);
	
    }
};