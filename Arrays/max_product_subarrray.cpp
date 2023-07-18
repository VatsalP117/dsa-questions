#include<vector>

int subarrayWithMaxProduct(vector<int> &arr){
	// Write your code here.
	int n=arr.size();
	long long maxi=0;
	long long pre=1;
	long long suff=1;
	for(int i=0;i<n;i++){
		if(pre==0) pre=1;
		if(suff==0) suff=1;

		pre=pre*arr[i];
		suff=suff*arr[n-i-1];
		maxi=max(maxi,max(pre,suff));
	}
	return maxi;
}