  //link: https://leetcode.com/problems/k-closest-points-to-origin/
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,vector<int>>> pq; //max heap on distance from origin
        vector<vector<int>> ans;
        for(auto it:points){
            int dist=pow(it[0],2) + pow(it[1],2); //x^2 + y^2
            pq.push({dist,it});
            if(pq.size()>k) pq.pop();
        }
        //heap now has our ans
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }