	void dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &res){
	    vis[node]=1;
	    for(auto adjNode:adj[node]){
	        if(vis[adjNode]==0) dfs(adjNode,adj,vis,res);
	    }
	    res.push_back(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V,0);
	    vector<int> res;
	    for(int i=0;i<V;i++){
	        if(vis[i]==0){
	            dfs(i,adj,vis,res);
	        }
	    }
	    reverse(res.begin(),res.end());
	    return res;
	}