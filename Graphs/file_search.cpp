//link: https://www.interviewbit.com/problems/file-search/
You are given an assignment to sort out the files of your department today.

A file contains various records. Each record has an (ID, Parent ID).

To make your task easier, you decided to separate records into different sets.

If a set contains a record with (ID, Parent ID) - (X, Y), then both X and Y must be present in the set.

There are A records. You are also given a 2D array B of dimensions N x 2,

where each row is record's (ID, Parent ID).



You have to find the maximum number of sets you can divide the records into.

//idea: basically find number of conncected components using disjoint set
//my apparoach (pata nahi kaise chala)
void dfs(int node,vector<vector<int>> &adj,vector<int>&vis){
    vis[node]=1;
    for(auto adjNode:adj[node]){
        if(vis[adjNode]==0){
            dfs(adjNode,adj,vis);
        }
    }
}
int Solution::breakRecords(int A, vector<vector<int> > &B) {
    //since A records so A nodes from1 ..A
    vector<vector<int>> adj(A+1);
    for(auto it: B){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    int res=0;
    vector<int> vis(A+1,0);
    for(int i=1;i<=A;i++){
        if(vis[i]==0){
            res++;
            dfs(i,adj,vis);
        }
    }
    return res;
}

//optimal
vector < int > ran, par;
int get(int a) {
    return par[a] = (par[a] == a ? a : get(par[a]));
}
void union1(int a, int b) {
    a = get(a);
    b = get(b);
    if (ran[a] == ran[b])
        ran[a]++;
    if (ran[a] > ran[b])
        par[b] = a;
    else par[a] = b;
}
int Solution::breakRecords(int A, vector < vector < int > > & B) {
    ran.clear();
    ran.resize(A + 1);
    par.clear();
    par.resize(A + 1);
    for (int i = 1; i <= A; i++) {
        par[i] = i;
    }
    int m = B.size();
    int ans = A;
    for (int i = 0; i < m; i++) {
        if (get(B[i][0]) == get(B[i][1]))
            continue;
        ans--;
        union1(B[i][0], B[i][1]);
    }
    return ans;
}