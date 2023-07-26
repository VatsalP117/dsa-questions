//link: https://www.codingninjas.com/studio/problems/connect-n-ropes-with-minimum-cost_625783?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

int minCost(int arr[], int n)
{

	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=0;i<n;i++){
		pq.push(arr[i]);
	}
	int cost=0;
	while(pq.size()>=2){
		int r1=pq.top();
		pq.pop();
		int r2=pq.top();
		pq.pop();
		pq.push(r1+r2);
		cost+=r1+r2;
	}
	return cost;
}