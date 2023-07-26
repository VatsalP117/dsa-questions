//link: https://www.codingninjas.com/studio/problems/merge-k-sorted-arrays_975379?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

#include <bits/stdc++.h> 
typedef pair<int,pair<int,int>> data;
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    vector<int> ans;
    //data is basically {value,{which_array,index_in_that_array}}
    priority_queue<data,vector<data>,greater<data>> pq; //min-heap
    int numArrays=kArrays.size();
    for(int i=0;i<numArrays;i++){
        vector<int> arr=kArrays[i];
        pq.push({arr[0],{i,0}});
        //push first element of all arrays
    }
    //start iterating over heap
    while(!pq.empty()){
        data it=pq.top();
        pq.pop();
        int val=it.first;
        int whichArr=it.second.first;
        int index=it.second.second;
        ans.push_back(val);
        vector<int> arr=kArrays[whichArr];
        if(index+1<arr.size()){
            pq.push({arr[index+1],{whichArr,index+1}});
        }
    }
    return ans;
}