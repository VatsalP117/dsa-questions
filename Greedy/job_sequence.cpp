#include <bits/stdc++.h> 
static bool cmp(vector<int> &a,vector<int> &b){
    return a[1]>b[1];
    //sort in descending order of profits
}
int find_max_deadline(vector<vector<int>> &arr){
    int res=0;
    for(int i=0;i<arr.size();i++){
        res=max(res,arr[i][0]);
    }
    return res;
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    //idea: first sort in descending order of profits
    //then start iterating do the job b on last deadline day
    //so that job b with higher deadline is performed later leaving space for job a with shorter deadline
    sort(jobs.begin(),jobs.end(),cmp);
    int max_deadline=find_max_deadline(jobs);
    vector<int> day_tasks(max_deadline+1,0);
    int ans=0;
    for(auto it:jobs){
        int profit=it[1];
        int deadline=it[0];
        int ptr=deadline;
        while(ptr>=1){
            if(day_tasks[ptr]==0){
                day_tasks[ptr]=1;
                ans+=profit;
                break;
            }
            ptr--;
        }
        
    }
    return ans;

}