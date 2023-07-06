//my solution (fails 2/54 cases where input vvv big)
int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//{time_to_reach_node,node}
        vector<int> time_to_reach(n,1e8);
        vector<int> dist(n,0);
        vector<vector<pair<int,int>>> adj(n);
        //create adjList now
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int time_taken=it[2];
            adj[u].push_back({v,time_taken});
            adj[v].push_back({u,time_taken});
        }
        //initial config
        pq.push({0,0});//zero time to reach node 0
        time_to_reach[0]=0;
        dist[0]=1;
        int mod = (int)(1e9 + 7);
        while(!pq.empty()){
            int curr_time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                int edW=it.second;
                if(curr_time+edW<time_to_reach[adjNode]){
                    //we have found a better path
                    pq.push({curr_time+edW,adjNode});
                    time_to_reach[adjNode]=curr_time+edW;
                    dist[adjNode]=dist[node]%mod;
                }
                else if(curr_time+edW==time_to_reach[adjNode]){
                    dist[adjNode]=(dist[adjNode]+dist[node])%mod;
                }
            }
        }
        
        return (dist[n-1]%mod);
    }
//leetcode solution
int countPaths(int n, vector<vector<int>>& a) {
          vector<pair<long long, long long>> adj[n];
        // it -> from to weight
        for(auto it:a){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<long long> ways(n, 0);
        vector<long long> dist(n, LONG_MAX);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq; // dist node
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;
        while(!pq.empty()){
            long long d = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                long long wt = it.second;
                long long adjnode = it.first;
                if(d + wt < dist[adjnode]){
                    dist[adjnode] = d + wt;
                    ways[adjnode] = ways[node];
                    pq.push({ dist[adjnode], adjnode});
                }
                else if(d + wt == dist[adjnode])
                         ways[adjnode]=((ways[adjnode] % 1000000007 + ways[node]) % 1000000007) % 1000000007;
            }
        }
        return ways[n - 1] % 1000000007;
    }

