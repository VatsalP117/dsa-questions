#include<vector>

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	// Write your code here.
	int n=arr.size();
	sort(arr.begin(),arr.end());
	vector<vector<int>> ans;
	for(int i=0;i<n;i++){
		if(ans.empty()|| arr[i][0]>ans.back()[1]){
			ans.push_back(arr[i]);
		}
		else{
			//can merge
			//if my end is more i will expand you else i will get into you
			ans.back()[1]=max(ans.back()[1],arr[i][1]);
		}
	}
	return ans;

	
}