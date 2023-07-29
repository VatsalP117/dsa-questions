#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
static bool cmp(pair<int,int> a,pair<int,int> b){
    //first is always bigger than second
    if(a.first!=b.first){
        return a.first>b.first;
    }
    else return a.second>b.second;
}
int find_min_cost(vector<int> &arr,int n,vector<pair<int,int>> &ans){
    int res=0;
    int min_building=arr[0];
    for(int i=arr.size()-1;i>=1;i--){
        res+=min_building+arr[i];
        ans.push_back({arr[i],arr[0]});
    }
    return res;
}
void dfs(int node,vector<vector<int>> &adj,vector<int> &vis){
    vis[node]=1;
    for(auto adjNode:adj[node]){
        if(vis[adjNode]==0){
            dfs(adjNode,adj,vis);
        }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    int m;
    cin>>n;
    cin>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u;
        int v;
        cin>>u;
        cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> compo;
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            compo.push_back(i);
            dfs(i,adj,vis);
        }
    }
    vector<pair<int,int>> ans;
    int cost=find_min_cost(compo,compo.size(),ans);
    sort(ans.begin(),ans.end(),cmp);
    cout<<compo.size()-1<<" "<<cost<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    return 0;
}
