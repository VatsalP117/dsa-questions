class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //in the prerequisites vector [course,course2] means course2 is a prereq for course1
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto it:prerequisites){
            //it[1] is a prereq for it[0] course
            indegree[it[0]]++;
            //indegree shows the number of prereq for a particular course. i.e if indegree=0 we can do that course rn
            adj[it[1]].push_back(it[0]);
            //so edge from it[1]->it[0] showing it[1] is a prereq for it[0]. once indegree of a node=0 we can do it
        }
        vector<int> res;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                res.push_back(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto adjNode:adj[node]){
                //node is now done so prereq for courses -- that have node has prereq
                indegree[adjNode]--;
                if(indegree[adjNode]==0){
                    q.push(adjNode);
                    res.push_back(adjNode);
                }
            }
        }
        if(res.size()!=numCourses) return {};
        return res;
    }
};