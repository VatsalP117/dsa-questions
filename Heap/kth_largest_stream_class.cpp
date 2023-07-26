class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int K;
    int add(int val) {
        pq.push(val);
        if(pq.size()>K)pq.pop();
        return pq.top();
    }
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int i=0;i<nums.size();i++){
            add(nums[i]);
        }
    }
    
    
};