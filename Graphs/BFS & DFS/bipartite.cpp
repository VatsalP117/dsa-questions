//can be colored using 2 colors or not
bool dfs(int node,int color,vector<vector<int>> &graph,vector<int> &vis){
        vis[node]=color;
        for(auto adjNode:graph[node]){
            if(vis[adjNode]==color) return false;
            else if(vis[adjNode]==-1){
                if(dfs(adjNode,!color,graph,vis)==false) return false;
            }
        }
        return true;
    }

    
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> vis(V,-1);
        for(int i=0;i<V;i++){
            if(vis[i]==-1){
                if(dfs(i,0,graph,vis)==false) return false;
            }
        }
        return true;
    }