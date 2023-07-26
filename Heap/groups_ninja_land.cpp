//link:https://www.codingninjas.com/studio/problems/groups-in-ninja-land._1459215?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1
//brute force
#include <bits/stdc++.h> 
int isPossible(int reqSize,unordered_map<int,pair<int,int>> &um){
    for(auto it:um){
        if(it.second.first==reqSize){
            if(it.second.second>0){
                return it.first;
            }
        }
    }
    return -1;
}
vector<int> findGroups(vector<int> &arr) 
{
    // Write your code here.
    unordered_map<int,pair<int,int>> um;
    int n=arr.size();
    int count=-1;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        if(isPossible(arr[i],um)!=-1){
            ans[i]=isPossible(arr[i],um);
            um[ans[i]].second--;
        }
        else{
            count++;
            um[count]={arr[i],arr[i]-1};
            ans[i]=count;
            
            
        }
    }
    return ans;
}
