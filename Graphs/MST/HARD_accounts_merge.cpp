//link:https://leetcode.com/problems/accounts-merge/submissions/

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int> um;//mail and who it belongs to
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            //since 0th index has the name and we want the mails
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(um.find(mail)==um.end()){
                    um[mail]=i;
                }
                else{
                    //merge
                    ds.unionByRank(um[mail],i);
                }
            }
        }
        //disjoint set and map ready
        vector<vector<string>> merged(n);
        for(auto it:um){
            string mail=it.first;
            int node=ds.findUParent(it.second);
            merged[node].push_back(mail);

        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(merged[i].size()==0) continue;
            vector<string> v;
            v.push_back(accounts[i][0]);//pushing the name
            sort(merged[i].begin(),merged[i].end());
            for(auto it:merged[i]){
                v.push_back(it);
            }
            ans.push_back(v);
        }
        return ans;
    }
};