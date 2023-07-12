//first increasing then decreasing (^ jaisa)
//can be just inc or just dec as well
#include <bits/stdc++.h> 
int longestBitonicSequence(vector<int>& arr, int n) {
	  // Write your code here.	   
		vector<int> dp1(n,1);
		vector<int> dp2(n,1);
		//check LIS: lis from beggining
		//check LIS2 : LIS  from end (manje decreasing)

		for(int i=1;i<n;i++){
			for(int prev=0;prev<i;prev++){
				if(arr[i]>arr[prev]){
					dp1[i]=max(dp1[i],1+dp1[prev]);
				}
			}
			
		}
		for(int i=n-2;i>=0;i--){
			for(int prev=n-1;prev>i;prev--){
				if(arr[i]>arr[prev]){
					dp2[i]=max(dp2[i],1+dp2[prev]);
				}
			}
		}
		int maxi=1;
		for(int i=0;i<n;i++){
			maxi=max(maxi,dp1[i]+dp2[i]);
		}
		return maxi-1;

} 