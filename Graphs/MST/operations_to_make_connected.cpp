lass DisjointSet{
        vector<int> rank;
        public:vector<int> parent;
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
                else return findUParent(parent[u]);
            }
            void unionByRank(int u,int v){
                int pu=findUParent(u);
                int pv=findUParent(v);

                //case1
                if(pu==pv){
                    return;
                }
                //case2
                if(rank[pu]<rank[pv]){
                    parent[pu]=pv;
                }
                else if(rank[pv]<rank[pu]){
                    parent[pv]=pu;
                }
                else{
                    parent[pu]=pv;
                    rank[pv]++;
                }
            }
    };
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extra_edges=0;
        DisjointSet ds(n);
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findUParent(u)!=ds.findUParent(v)){
                ds.unionByRank(u,v);
            }
            else{
                extra_edges++;
            }
        }
        int numComponents=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                numComponents++;
            }
        }
        if(numComponents==1) return 0;
        int edges_required=numComponents-1;
        if(extra_edges>=edges_required) return edges_required;
        else return -1;
    }