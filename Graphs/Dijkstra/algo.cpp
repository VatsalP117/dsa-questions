 vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        //edges is made of vectors like [u,v,w],[u1,v1,w1]
        vector<vector<pair<int,int>>> adj(N);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        //adj List is ready
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //we will store {edge,node} in pq such that smallest edge comes out first
        vector<int> dist(N,-1);
        
        //initial config
        pq.push({0,0});
        dist[0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            int dis=it.first;
            int node=it.second;
            pq.pop();
            for(auto i:adj[node]){
                int adjNode=i.first;
                int edW=i.second;
                if(dis+edW<dist[adjNode] ||dist[adjNode]==-1){
                    dist[adjNode]=dis+edW;
                    pq.push({dis+edW,adjNode});
                }
            }
        }
        return dist;
    }