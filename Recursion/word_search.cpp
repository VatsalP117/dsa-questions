//link: https://leetcode.com/problems/word-search/
class Solution {
public:
    bool solve(int ind,int row,int col,int m,int n,string &word,vector<vector<char>>& board,vector<vector<int>> &vis){
        if(ind==word.size()){
            return true;
        }
        //now search for the current character
        bool ans=false;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int rr=row+dr[i];
            int cc=col+dc[i];
            if(rr>=0 && rr<m && cc>=0 && cc<n && vis[rr][cc]==0 && board[rr][cc]==word[ind]){
                vis[rr][cc]=1;
                ans=ans||solve(ind+1,rr,cc,m,n,word,board,vis);
                vis[rr][cc]=0;
            }
        }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=1;
                    if(solve(1,i,j,m,n,word,board,vis)){
                        return true;
                    }
                    vis[i][j]=0;
                }
            }
        }
        return false;
    }
};