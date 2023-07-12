int searchInsert(vector<int>& arr, int m)
{
	// Write your code here.
	int n=arr.size();
	int low=0;
	int high=n-1;
	int ans=n;
	while(low<=high){
		int mid=(low+high)/2;
		//arr has all distinct values
		if(arr[mid]==m){
			return mid;
		}
		else if(arr[mid]<m){
			low=mid+1;
		}
		else{
			//arr[mid]>x
			//can insert here
			ans=mid;
			//but also see if possible to insert before
			high=mid-1;
		}
	}
	return ans;
}