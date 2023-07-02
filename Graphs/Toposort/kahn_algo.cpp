	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	  vector<int> indegree(V,0);
	  vector<int> res;
	  for(int i=0;i<V;i++){
	      for(auto it:adj[i]){
	          indegree[it]++;
	      }
	  }
	  queue<int> q;
	  for(int i=0;i<V;i++){
	      if(indegree[i]==0){
	          q.push(i);
	          res.push_back(i);
	      }
	  }
	  while(!q.empty()){
	      int node=q.front();
	      q.pop();
	      for(auto adjNode:adj[node]){
	          indegree[adjNode]--;
	          if(indegree[adjNode]==0){
	              q.push(adjNode);
	              res.push_back(adjNode);
	          }
	      }
	  }
	  return res;
	}