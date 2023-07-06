  int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        vector<int> pre(N,0);
        unordered_map<int,int> um;
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
            pre[i]=sum;
            if(um.find(sum)==um.end()){
                um[sum]=i;
            }
         
        }
  

        int res=0;
        int count=0;
        for(int i=0;i<N;i++){
            int val=pre[i];
            if(val==K){
                res=max(res,i+1);
                continue;
            }
            auto it=um.find(val-K);
            
            if(it!=um.end()){
                // cout<<val<<" at "<<i<<" "<<it->second<<" found "<<val-K<<endl;
                res=max(res,i-it->second);
            }
        }
      
        return res;
    } 