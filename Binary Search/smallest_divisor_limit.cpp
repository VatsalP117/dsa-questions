int find_max(vector<int> &arr){
	int res=-1;
	for(int i=0;i<arr.size();i++){
		if(arr[i]>res){
			res=arr[i];
		}
	}
	return res;
}
bool chalega_kya(vector<int> &arr,int limit,int divisor){
	int res=0;
	for(int i=0;i<arr.size();i++){
		if(arr[i]%divisor==0){
			res+=arr[i]/divisor;
		}
		else{
			res+=arr[i]/divisor +1 ;
		}
	}
	if(res<=limit) return true;
	else return false;
}
int smallestDivisor(vector<int>& arr, int limit)
{
	// Write your code here.
	int n=arr.size();
	int low=1;
	int high=find_max(arr)+1;
	int ans=high;
	while(low<=high){
		int mid=(low+high)/2;
		if(chalega_kya(arr,limit,mid)==false){
			//not working so try something bigger
			low=mid+1;
		}
		else{
			ans=mid;
			high=mid-1;
		}
	}
	return ans;
}