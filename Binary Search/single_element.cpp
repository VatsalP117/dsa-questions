//leetcode 540
//You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.
class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n=arr.size();
        //base cases handle pehle se hi
        if(n==1) return arr[0];
        if(arr[0]!=arr[1]) return arr[0];
        if(arr[n-2]!=arr[n-1]) return arr[n-1];
        //now real deal
        int low=1;
        int high=n-2;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid-1]!=arr[mid] && arr[mid+1]!=arr[mid]){
                return arr[mid];
            }
            //number of elements on your left(notcounting yourself)
            int numLeft=mid;
            int numRight=n-mid-1;
            if(arr[mid-1]==arr[mid]){
                //means apna saathi left mai hai
                //to left side should have an extra element if all others are with their pairs(left should hav eoff number of elements)
                //if not, means vo single element udhar hai
                if(numLeft%2==0){
                    //means single banda waha hai
                    high=mid-1;
                }
                else low=mid+1;
            }
            else if(arr[mid+1]==arr[mid]){
                //means ideally right should have odd elements if single element is not there
                if(numRight%2==0){
                    low=mid+1;
                }
                else high=mid-1;
            }
        }
        return -1;
    }
};