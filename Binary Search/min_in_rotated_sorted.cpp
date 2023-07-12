int findMin(vector<int>& arr)
{	
	//check which half is sorted, 
	//the other half will contain the point of rotation so the minimum element
	//but the sorted may or may not contain the min point so while eliminating it just store the min element of the sorted part
	// Write your code here.
	int n=arr.size();
	int low=0;
	int high=n-1;
	int ans=INT_MAX;
	while(low<=high){
		//basically pick the smallest from sorted and eliminate it
		int mid=(low+high)/2;
		if(arr[low]<=arr[mid]){
			//left half sorted
			ans=min(ans,arr[low]);
			low=mid+1;
		}
		else{
			//right half sorted
			ans=min(ans,arr[mid]);
			high=mid-1;
		}
	}
	return ans;

}