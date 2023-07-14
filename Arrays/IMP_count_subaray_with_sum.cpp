int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    // Write Your Code Here
    int n=arr.size();
    vector<int> ps(n,0);
    unordered_map<int,int> um;
    int curr_sum=0;
    int res=0;
    for(int i=0;i<n;i++){
        curr_sum+=arr[i];
        ps[i]=curr_sum;
        um[ps[i]]++;
        if(ps[i]==k){
            res++;
        }
        if(um.find(ps[i]-k)!=um.end()){
            res+=um.find(ps[i]-k)->second;
        }
    }
    return res;
}