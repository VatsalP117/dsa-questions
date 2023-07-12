int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int low=0;
	int high=n-1;
	int ans=n;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]<x){
			low=mid+1;
		}
		else{
			//we found someone that can be ans so lets store it
			//now we go left to find if we can find someone smaler that can be ans
			//we always move left here so if we find someone, it will always be smaller
			ans=mid;
			high=mid-1;
		}
	}
	return ans;
}