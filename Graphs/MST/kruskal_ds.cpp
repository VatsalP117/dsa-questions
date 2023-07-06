class DisjointSet{
	    vector<int> rank;
	    vector<int> parent;
	    public:
	        DisjointSet(int n){
	            rank.resize(n+1,0);
	            parent.resize(n+1);
	            for(int i=0;i<=n;i++){
	                parent[i]=i;
	            }
	        }
	        int findUParent(int u){
	            if(u==parent[u]) return u;
	            return parent[u]=findUParent(parent[u]);
	        }
	        void unionByRank(int u,int v){
	            int pu=findUParent(u);
	            int pv=findUParent(v);
	            if(pu==pv){
	                //already a part of same component so no need
	                return;
	            }
	            //rule: connect smaller rank to the higher rank guy
	            if(rank[pu]<rank[pv]){
	                
	                parent[pu]=pv;
	            }
	            else if(rank[pv]<rank[pu]){
	                parent[pv]=pu;
	            }
	            else{
	                //equal rank connect any to any
	                parent[pu]=pv;
	                rank[pv]++;
	            }
	        }
	};
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
       //DisJoint Set is ready
       DisjointSet ds(V);
       vector<pair<int,pair<int,int>>> edges;
       for(int i=0;i<V;i++){
           for(auto it:adj[i]){
               //basically all the edges of node i are in the form [adjNode,weight]
               edges.push_back({it[1],{i,it[0]}});
           }
       }
       //sort the edges array to have smallest edges first
       sort(edges.begin(),edges.end());
       int mstWt=0;
       for(auto it:edges){
           int edW=it.first;
           int u=it.second.first;
           int v=it.second.second;
           if(ds.findUParent(u)!=ds.findUParent(v)){
               ds.unionByRank(u,v);
               mstWt+=edW;
           }
       }
       return mstWt;
    }