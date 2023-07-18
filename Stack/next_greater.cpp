#include <bits/stdc++.h>
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	// Write your code here
	vector<int> ans(n,-1);
	if(n==0) return ans;
	stack<int> st;
	for(int i=n-1;i>=0;i--){
		
		while(!st.empty()  && st.top()<=arr[i]){
			//removed all smaller elements from stack since they are of no use now
			st.pop();
		}
		if(st.empty()){
			//means no greater element on right
			ans[i]=-1;
		}
		else{
			ans[i]=(st.top());
		}
		st.push(arr[i]);
	}
	return ans;

}