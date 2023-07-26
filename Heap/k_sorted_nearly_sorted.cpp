//link; https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//Given an array of n elements, where each element is at most k away from its target position, you need to sort the array optimally

#include <bits/stdc++.h> 
vector < int > nearlySorted(vector < int > arr, int n, int k) {
    // Write your code here.
    //idea of using heap is: jo index 0 pe aana chaiye uske liye bas 0 se k wale elements compare karne h
    //saare compare karne ka zarurat nahi
    //vaise hi index 1 pe hoga uske lye uske pehle aur aage ke k elements mai hi dekhna h
    //to bas heap mai utne hi rakho
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> ans;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>k){
            ans.push_back(pq.top());
            pq.pop();
        }
    }
    while(pq.empty()==false){
        ans.push_back(pq.top());
        pq.pop();
}
    return ans;
    }