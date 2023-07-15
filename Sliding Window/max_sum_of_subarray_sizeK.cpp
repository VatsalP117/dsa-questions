    long maximumSumSubarray(int K, vector<int> &arr , int N){
        // code here 
        long sum=0;
        long res=0;
        int i=0; //start
        int j=0; //end
        while(j<N){
            sum+=arr[j];
            
            //if window size not hit yet keep increasing window size
            if(j-i+1<K){
                j++;
            }
            else if(j-i+1==K){
                //window condition achieved
                res=max(res,sum);
                sum=sum-arr[i];
                //bas maintain window size now
                i++;
                j++;
            }
        }
        return res;
    }