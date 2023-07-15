#include <bits/stdc++.h>
vector<int> firstNegative(vector<int> arr, int n, int k) {
	int i=0;//start
	int j=0;//end
	queue<int> q;
	vector<int> ans;
	while(j<n){
		//calculations to karna hi hai
		if(arr[j]<0){
			q.push(j);
		}

		//window size nahi aayi to badhate jao pahochne tak
		if(j-i+1<k){
			j++;
		}

		//a gayi window size to calculation se ans nikalo
		//aur window aage slide karo
		else if(j-i+1==k){
			if(q.empty()){
				ans.push_back(0);
			}
			else{
                //calculation se ans nikal lo
				ans.push_back(arr[q.front()]);

                //now slide
				//agar winoow ke bahar jaa raha h number to queue se bhi hata do
				if(q.empty()==false && i==q.front()){
					q.pop();
				}
				
			}
			i++;
			j++;
		}
	}
	return ans;
}