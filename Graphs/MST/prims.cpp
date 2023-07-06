int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> vis(V,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        //now initial config
        pq.push({0,0});
       
        int res=0;
        while(!pq.empty()){
            auto i=pq.top();
            int edW=i.first;
            int node=i.second;
            pq.pop();
            if(vis[node]==1) continue; //already a part of MST
            //add to MST
            vis[node]=1;
            res+=edW;
            for(auto it:adj[node]){
                int new_edge=it[1];
                int adjNode=it[0];
                if(vis[adjNode]==0){
                    pq.push({new_edge,adjNode});
                }
            }
        }
        return res;
    }