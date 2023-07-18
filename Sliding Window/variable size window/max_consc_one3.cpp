//link: https://www.codingninjas.com/studio/problems/maximum-consecutive-ones_892994?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1
int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int count=0;
    int res=0;
    int i=0;
    int j=0;
    while(j<n){
        //calculations
        if(arr[j]==0){
            count++;
        }
        //check it overshoots
        if(count>k){
            while(count>k){
                if(arr[i]==0){
                    count--;

                }
                i++;
            }
        }
        if(count<=k){
            res=max(res,j-i+1);
        }
        j++;
    }
    return res;
}
