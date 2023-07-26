//link: https://www.codingninjas.com/studio/problems/replace-each-element-of-array-with-its-corresponding-rank_975384?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1


#include <bits/stdc++.h> 
vector<int> replaceWithRank(vector<int> &arr, int n) 
{
 	// Write your code here
	 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	 for(int i=0;i<n;i++){
		 pq.push({arr[i],i});
	 }
	 vector<int> ans(n);
	 int curr_rank=0;
	 int prev=INT_MIN;
	 while(!pq.empty()){
		 auto it=pq.top();
		 int index=it.second;
		 int val=it.first;
		 pq.pop();
		 if(val>prev) curr_rank++;
		 ans[index]=curr_rank;
		 prev=val;
	 }
	 return ans;
}