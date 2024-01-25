//leetcode 2865
// Idea
// Asume every index of array as peak & one by one try to calulate the sum & finally return the max of all the sums
// NOTE : From peak ind , elements to its left & right has to be in decreasing order

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n=maxHeights.size();
        long long ans=0;
        //idea: consider every point as partition point and see if it works
        for(int i=0;i<n;i++){
            vector<int> arr(n);//stores heights of left partition
            arr[i]=maxHeights[i];
            //apna ith element is the last element of partiton => means it should be the biggest element
            //left partition
            for(int j=i-1;j>=0;j--){
                arr[j]=min(maxHeights[j],arr[j+1]);
            }
            //right partition
            //ith element should be the smallest
            for(int j=i+1;j<n;j++){
                arr[j]=min(arr[j-1],maxHeights[j]);
            }
            //calculate ans for this partition
            long long res=accumulate(arr.begin(),arr.end(),0LL);
            ans=max(ans,res);
        }
        return ans;
    }
};