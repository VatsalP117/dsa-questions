//queue works since distances will only increase gradually
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,1e8));
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        q.push({1,{0,0}});
        dist[0][0]=1;
        while(!q.empty()){
            auto it=q.front();
            int weight=it.first;
            int row=it.second.first;
            int col=it.second.second;
            q.pop();
            if(row==n-1 && col==n-1) return weight;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int rr=row+i;
                    int cc=col+j;
                    if(rr>=0 && rr<n && cc>=0 && cc<n && grid[rr][cc]==0){
                        if(weight+1<dist[rr][cc]){
                            q.push({weight+1,{rr,cc}});
                            dist[rr][cc]=weight+1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};