//link: https://www.codingninjas.com/studio/problems/k-most-frequent-elements_3167808?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
#include <bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int,int> um;//to store number with their frequency
    for(int i=0;i<n;i++){
        um[arr[i]]++;
    }
    //ab largest frequency chaiye to ek min heap banado
    //so that heap mai k elements rahenge an djo bhi usse kam frequency wale honge sab pop
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(auto it:um){
        pq.push({it.second,it.first});//key is frequency
        if(pq.size()>k) pq.pop();
    }
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}