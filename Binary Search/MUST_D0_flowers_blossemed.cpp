//lc hard question i did all by myself so very happy about this
//link: https://leetcode.com/problems/number-of-flowers-in-full-bloom/submissions/


// Approach:
// just separate the start and end times of the flowers and put them in an array 
// buy this for a particlar time, we can just find out the number of flowers that started their full prime phase before that and those that died before that 
// so we can see number of flowers=those started before - those ended before

// but how to do this efficiently?
// sort both the start and die vectors and apply binary search 
// find the largest index i sucht that start[i]<=our start time 
// and i+1(just num of elements till index i) will be the number of elements those started prime phase before our time 
// and do the same for end and its done!


class Solution {
public:
    int find_before(vector<int> &arr,int num){
        int n=arr.size();
        //to find the biggest number in arr that is <=num
        int low=0;
        int high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>num){
                //zyada bada ho gya go left pls
                high=mid-1;
            }
            else{
                ans=mid;
                low=mid+1;
            }
        }
        return ans+1;
        
    }
        int find_die(vector<int> &arr,int num){
        int n=arr.size();
        //to find the biggest number in arr that is <num
        int low=0;
        int high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>=num){
                //zyada bada ho gya go left pls
                high=mid-1;
            }
            else{
                ans=mid;
                low=mid+1;
            }
        }
        return ans+1;
        
    }

    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start;
        vector<int> die;
        for(auto it:flowers){
            start.push_back(it[0]);
            die.push_back(it[1]);
        }
        sort(start.begin(),start.end());
        sort(die.begin(),die.end());
        vector<int> ans;
        for(auto &it:people){
            int num_start=find_before(start,it);
            int num_died=find_die(die,it);
            ans.push_back(max(0,num_start-num_died));
        }
        return ans;
        
        
        
    }
};