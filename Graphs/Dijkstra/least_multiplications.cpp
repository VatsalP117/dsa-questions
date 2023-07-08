 int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
       queue<pair<int,int>> q;//{steps_to_reach_node,node}
       int mod=1e5;
       vector<int> dist(1e5,1e8);
       //initial config
       dist[start]=0;
       q.push({0,start});
       while(!q.empty()){
           int steps=q.front().first;
           int node=q.front().second;
           q.pop();
           if(node==end) return steps;
           for(auto it:arr){
               int num=(it*node)%mod;
               if(steps+1<dist[num]){
                   q.push({steps+1,num});
                   dist[num]=steps+1;
               }
           }
       }
       return -1;
       
    }