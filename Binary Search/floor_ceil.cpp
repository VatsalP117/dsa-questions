pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	// Write your code here.
	//floor=largest element which is <=x
	//ceil: smallest element >=x (basically lower bound)
	sort(arr,arr+n);
	int low=0;
	int high=n-1;
	int floor=-1;
	int ceil=-1;
	while(low<=high){
		//floor nikal lete
		int mid=(low+high)/2;
		if(arr[mid]>x){
			//cannot be our ans since we want someone smaller
			//so go left
			high=mid-1;

		}
		else{
			//can be our ans
			floor=arr[mid];
			//but also search if we can find a larger value <=x on the right
			low=mid+1;
		}
	}
	low=0;
	high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]<x){
			//cannot be our ans
			//search for a bigger value on the right
			low=mid+1;
		}
		else{
			ceil=arr[mid];
			//search is a smaller value suits the condition on the right
			high=mid-1;
		}
	}
	return {floor,ceil};
}
