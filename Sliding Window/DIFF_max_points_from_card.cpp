//linK;https://www.codingninjas.com/studio/problems/maximum-points-from-cards_8391016?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1
N maise k cards uthane either from start or end of window
means N-k nahi lene
find these N-k wala window s.t uska sum is min
//cant take direct window=k size and max sum since it might give a window like 1 [4 5 6] 2 3 which is not allowed since aage piche se uthana h
int maxPoints(vector<int>&arr , int K){
    // Write your code here.
    int n=arr.size();
    int to_leave=n-K;//K cards lenge to n-k chodh denge na
    //basically find window of size n-k with minimum sum
    int i=0;
    int j=0;
    int tot_sum=0;
    for(int val:arr) tot_sum+=val;
    int res=INT_MAX;
    int sum=0;
    if(to_leave==0) return tot_sum;
    while(j<n){
        sum+=arr[j];
        if(j-i+1<to_leave){
            j++;
        }
        else if(j-i+1==to_leave){
            res=min(res,sum);
            sum-=arr[i];
            i++;
            j++;
        }
    }
    return tot_sum-res;
}