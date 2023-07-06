class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //store in terms in stops first coz vo main priority hai apni
        queue<pair<int,pair<int,int>>> q; //{stops,{node,price}}
        //normal queue since stops will increse linearly
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            int src=it[0];
            int dest=it[1];
            int cost=it[2];
            adj[src].push_back({dest,cost});
        }
        vector<int> prices(n,1e8);
        prices[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto i=q.front();
            int stops=i.first;
            int node=i.second.first;
            int cost=i.second.second;
            q.pop();
            if(stops>k) continue;
            for(auto it:adj[node]){
                int adjNode=it.first;
                int edW=it.second;
                if(cost+edW<prices[adjNode]){
                    prices[adjNode]=cost+edW;
                    q.push({stops+1,{adjNode,cost+edW}});
                }
            }
        }
        if(prices[dst]==1e8)return -1;
        else return prices[dst];
    }
};