//https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
//cost to join two ropes= sum of lengths
//therefore humesha min length wale add karo
  long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>> pq;
      for(long long i=0;i<n;i++){
          pq.push(arr[i]);
      }
        long long res=0;
        while(pq.size()>1){
            long long r1=pq.top();
            pq.pop();
           
            long long r2=pq.top();
            pq.pop();
            res+=(r1+r2);
            pq.push(r1+r2);
            
        }
        return res;
    }