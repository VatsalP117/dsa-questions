//link:https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint/submissions/
// The set::lower_bound() is a built-in function in C++ STL which returns an iterator pointing to the element in the container which is equivalent to k passed in the parameter. In case k is not present in the set container, the function returns an iterator pointing to the immediate next element which is just greater than k. If the key passed in the parameter exceeds the maximum value in the container, then the iterator returned points to the element beyond last element in the set container. 

// Time Complexity of set::lower_bound() is O(logn), where n is the size of the set.
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        set<int> st;
        int minm = INT_MAX;
        for(int i=x;i<n;i++){
            //starting from x
            st.insert(nums[i-x]);
            auto it = st.lower_bound(nums[i]);
            //just next greater element
            
            if(it!=st.end())  minm = min(minm,abs(nums[i]-*(it)));
            if(it!=st.begin()){
                --it;
                minm = min(minm,abs(nums[i]-*(it)));
            }
        }
        
        return minm;
        
    }
};