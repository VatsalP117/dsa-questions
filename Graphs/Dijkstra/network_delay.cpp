class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);//
        for(auto it:times){
            int src=it[0];
            int dst=it[1];
            int time_delay=it[2];
            adj[src].push_back({dst,time_delay});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //{time_to_reach_node,node}
        vector<int> dist(n,1e8);

        //initial config
        dist[k]=0;
        pq.push({0,k});//need 0 time to reach node k since its the source lol
        while(!pq.empty()){
            int curr_time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                int edW=it.second;
                if(curr_time+edW<dist[adjNode]){
                    pq.push({curr_time+edW,adjNode});
                    dist[adjNode]=curr_time+edW;
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(dist[i]==1e8){
                return -1;
            }
            res=max(res,dist[i]);
        }
        return res;
    }
};