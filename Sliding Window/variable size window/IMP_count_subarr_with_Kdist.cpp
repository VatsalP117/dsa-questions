In the given context, 'R' represents the rightmost index of the subarray, and 'L' represents the leftmost index. The expression 'R - L + 1' calculates the number of subarrays that can be formed within the range from index 'L' to index 'R', inclusive.

To understand why this expression gives us the number of subarrays, let's consider an example. Suppose we have an array with 5 elements: [2, 4, 6, 8, 10].

If we select the leftmost index 'L' as 1 (the first element) and the rightmost index 'R' as 3 (the third element), 
we have the subarray [2, 4, 6]. In this case, 'R - L + 1' is equal to 3 - 1 + 1, which is 3. 
This means there are 3 subarrays that can be formed within this range: [2], [2, 4], and [2, 4, 6]

//link:https://www.codingninjas.com/studio/problems/subarrays-with-at-most-%E2%80%98k%E2%80%99-distinct-values_1473804?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=2
#include <bits/stdc++.h> 
int kDistinctSubarrays(vector<int> &arr, int n, int k)
{
    // Write your code here
    unordered_map<int,int> um;
    int count=0;
    int res=0;
    int i=0;
    int j=0;
    while(j<n){
        //calculations
        um[arr[j]]++;
        if(um[arr[j]]==1){
            count++;
        }

        //check if overshoots condition
        if(count>k){
            while(count>k){
                um[arr[i]]--;
                if(um[arr[i]]==0) count--;
                i++;
            }
        }
        if(count<=k){
            int len=j-i+1;
            //ab is subarray ke jitne subarray honge sabmai at most K values hi hongi na
            res+=len;
            
    
        }
        j++;
        
    }
    return res;
}