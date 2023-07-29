//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/submissions/
//basically connected components hi hai
class Solution {
public:
    void dfs(int ind,vector<vector<int>>& stones,vector<int> &vis){
        vis[ind]=1;
        int x=stones[ind][0];
        int y=stones[ind][1];
        for(int i=0;i<stones.size();i++){
            if(vis[i]==0){
                int x1=stones[i][0];
                int y1=stones[i][1];
                if(x1==x || y1==y){
                    dfs(i,stones,vis);
                }
            }
            
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                dfs(i,stones,vis);
            }
        }
        return n-ans;
    }
};