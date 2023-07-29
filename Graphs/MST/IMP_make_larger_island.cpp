//link:https://leetcode.com/problems/making-a-large-island/
class DisjointSet {
   public: vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                for(int ind=0;ind<4;ind++){
                    int adjR=i+dr[ind];
                    int adjC=j+dc[ind];
                    if(adjR>=0 && adjR<n && adjC>=0 && adjC<n && grid[adjR][adjC]==1){
                        int nodeNo=i*n +j;
                        int adjNo=adjR*n + adjC;
                        ds.unionBySize(nodeNo,adjNo);
                        
                    }
                }
            }
        }

        //all 1's are now connected
        //now look to check all zeros
        int res=-1;
          for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                unordered_set<int> s;
                for(int ind=0;ind<4;ind++){
                    int adjR=i+dr[ind];
                    int adjC=j+dc[ind];
                    if(adjR>=0 && adjR<n && adjC>=0 && adjC<n && grid[adjR][adjC]==1){
                        int adjNo=adjR*n + adjC;
                        s.insert(ds.findUPar(adjNo));
                        //s now has all ultimate parents of components adjacent to this 0
                        
                    }
                }
                int count=1;
                for(auto it:s){
                    count+=ds.size[it];
                }
                res=max(res,count);

               
            }
        }
        if(res==-1) return n*n;
        else return res;

    }
};