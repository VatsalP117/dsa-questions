//problem link: https://www.codingninjas.com/studio/problems/rose-garden_2248080?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1
int find_max(vector<int> &arr){
	int res=-1;
	for(int i=0;i<arr.size();i++){
		if(arr[i]>res){
			res=arr[i];
		}
	}
	return res;
}
int chalega_kya(vector<int> &arr,int m,int k,int curr_day){
	int num_bouquets=0;
	int curr_remaining=k;
	for(int i=0;i<arr.size();i++){
		if(curr_remaining==0){
			num_bouquets++;
			curr_remaining=k;
		}
		if(curr_day>=arr[i]){
			//means it has bloomed
			curr_remaining--;
		}
		else{
			curr_remaining=k;
		}
	}
	if(curr_remaining==0) num_bouquets++;
	if(num_bouquets>=m) return true;
	else return false;
}
int roseGarden(vector<int> arr, int k, int m)
{
	// Write your code here
	int n=arr.size();
	int low=1; //too optimise fruther take the min value in the array
	int high=find_max(arr);
	int ans=-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(chalega_kya(arr,m,k,mid)==false){
			//need more days bro
			low=mid+1;
		}
		else{
			//found an ans but we keep looking for a better one
			ans=mid;
			high=mid-1;

		}
	}
	return ans;
	
}