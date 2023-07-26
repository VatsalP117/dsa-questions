//return all k largest elements in an array
//Given an array Arr of N positive integers and an integer K, find K largest elements from the array.  The output elements should be printed in decreasing order

Intuition:
at any point heap mai k elements at max and jo bhi usse chota hai vo pop ho jayega since top pe chota hoga
so jo last mai k bachenge vo sabse bade honge
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    vector<int> ans(k);
	    //largest pucha hai to min heap banao
	    priority_queue<int,vector<int>,greater<int>> hp;
	    for(int i=0;i<n;i++){
	        hp.push(arr[i]);
	        if(hp.size()>k) hp.pop();
	    }
	    int ptr=k-1;
	    while(hp.empty()==false){
	        ans[ptr]=hp.top();
	        hp.pop();
	        ptr--;
	    }
	    return ans;
	}