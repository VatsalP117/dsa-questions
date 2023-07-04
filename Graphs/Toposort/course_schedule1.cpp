class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& preq) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        // vector<vector<int>> new_pre(numCourses);
        //indegree of any index indicated the number of pre req courses for that index
        //reverse the edges of graph
        for(auto it:preq){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        int res=0;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                //course with no pre req so we will definetly complete it
                res++;
                q.push(i);
            }
        }
        //initial config
        while(!q.empty()){
            int node=q.front();
            q.pop();
            //this course is now done
            for(auto adjNode:adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode]==0){
                    q.push(adjNode);
                    res++;
                }
            }
        }
        if(res==numCourses)return true;
        else return false;
    }
};