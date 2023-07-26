//k+smallest manje max heap
#include <bits/stdc++.h>
int kthSmallest(int n,int k,vector<int> arr)
{
    // Write your code here.
    priority_queue<int> hp;//max heap
    for(int i=0;i<n;i++){
        hp.push(arr[i]);
        //if size>k means element at top is already greater than k elements fir vo to apna ans pakka nahi
        //islie uska bhaga do
        //last mai heap mai k elements honge, top pe kth largest hoga
        if(hp.size()>k) hp.pop();
    }
    return hp.top();
}