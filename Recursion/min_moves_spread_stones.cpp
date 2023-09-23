//leetcode 2850: min moves to spread stones
typedef pair<int,int> p;
typedef pair<int,pair<int,int>> pp;
class Solution {
public:
    int solve(int ind,vector<p> &poor,vector<pp> &rich){
        if(ind==poor.size()) return 0;
        //ab is bande ko sab amir lago se dene ka try karo
        int ans=1e9;
        int x=poor[ind].first;
        int y=poor[ind].second;
        for(int i=0;i<rich.size();i++){
            if(rich[i].first>1){
                rich[i].first--;
                int richX=rich[i].second.first;
                int richY=rich[i].second.second;
                ans=min(ans,abs(richX-x)+abs(richY-y)+solve(ind+1,poor,rich));
                //backtracking step
                rich[i].first++;
            }
            
        }
        return ans;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        //grid will always be 3*3
        //ideais every cell with 0 will be given a stone by someone jiske paas extra hai
        //and we gotta try all combos to give a stone from every extra one to every 0
        //aur constraints itne lite to just use recursion
        //COMMUNISIM!!
        vector<p> poor; //inke paas kn h
        vector<pp> rich; //inke paas extra hai
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==0) poor.push_back({i,j});
                if(grid[i][j]>1) rich.push_back({grid[i][j],{i,j}});
            }
        }
        if(poor.size()==0) return 0;
        return solve(0,poor,rich);
    }
};