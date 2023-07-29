//link: https://practice.geeksforgeeks.org/problems/number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-islands
class DisjointSet{
    vector<int> parent;
    vector<int> rank;
    public:DisjointSet(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findUParent(int u){
        if(u==parent[u])return u;
        else return findUParent(parent[u]);
    }
    void unionByRank(int u,int v){
        int pu=findUParent(u);
        int pv=findUParent(v);
        if(pu==pv){
            //already part of samw component
            return;
        }
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        //n=num rows, m=num_cols
        DisjointSet ds(n*m);
        int count=0;//num of components
        vector<int> ans;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            if(vis[row][col]==1){
                ans.push_back(count);
                continue;
            }
            vis[row][col]=1;
            count++; //treat this as a new island and try to merge later
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int adjR=row+dr[i];
                int adjC=col+dc[i];
                if(adjR>=0 && adjR<n && adjC>=0 && adjC<m && vis[adjR][adjC]==1){
                    //convert our row_col to a number between 0..n*m
                    int nodeNo=row*m +col;
                    int adjNo=adjR*m +adjC;
                    if(ds.findUParent(nodeNo)!=ds.findUParent(adjNo)){
                        count--;
                        ds.unionByRank(nodeNo,adjNo);
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};