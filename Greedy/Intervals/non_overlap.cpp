//link: https://leetcode.com/problems/non-overlapping-intervals/submissions/
//link: https://leetcode.com/problems/insert-interval/solutions/3056444/daily-leetcoding-challenge-january-day-16/
Greedy approach: since we want to minimise the number of intervals to remove, we will remove one that has the largest end
since vo jitna lamba chalega utne zyada intervals ki jagah le jayega .(since larger one might overlap with other intervals as well)
static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n=intervals.size();
        if(n==0) return 0;
        int res=0;

        int right=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=right){
                //not bt isse to apne ko
                
                right=intervals[i][1];
            }
            else{
                //just remove this bastard
                res++;
            }
        }
        return res;
    }
};