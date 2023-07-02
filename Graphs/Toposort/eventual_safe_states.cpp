 vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //all terminal nodes are safe nodes
        //if we reverse all the edges and then removr all the edges startting from terminal nodes
        //then if a node has indegree=0 means it only had edges from safe/terminal nodes

        int V=graph.size();
        vector<vector<int>> newGraph(V);
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it:graph[i]){
                newGraph[it].push_back(i);
                indegree[i]++;
            }
        }
        //new graph ready with reversing
        vector<int> res;
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
                res.push_back(i);
            }
        }
        //all terminal nodes in q for initial config
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:newGraph[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    res.push_back(it);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }