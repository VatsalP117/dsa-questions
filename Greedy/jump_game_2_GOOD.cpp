//BASICALLY RETURN MIN NUM NUMBER OF STEPS TO REACH DESTINATION

//my code(works on leetcode, tle on coding ninja)
    int jump(vector<int>& arr) {
         int n=arr.size();
    vector<int> steps_to_reach(n,-1);
    steps_to_reach[n-1]=0;
    
    for(int i=n-2;i>=0;i--){
        int curr_index=i;
        int mini=1e8;
        for(int j=1;j<=arr[i];j++){
            int possible_destination=(i+j);
            if(possible_destination>n-1) break;
            mini=min(mini,1+steps_to_reach[possible_destination]);
        }
        steps_to_reach[i]=mini;
    }
    return steps_to_reach[0];
};