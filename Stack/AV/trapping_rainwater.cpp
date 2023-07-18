long long getTrappedWater(long long* arr, int n) {
    // Write your code here.

    //IDEA: YAHA NEXT SMALLER ON LEFT/RIGHT VO SAB CONCEPTS NAHI LAGENGE
    //BASICALLY PAANI BOUNDED BY MAX HEIGHT ON LEFT AND RIGHT
    //SO FIND MAX HEIGHT ON LEFT/RIGJT FRO EACH ELEMENT

    vector<long long> leftMax(n);
    vector<long long> rightMax(n);
    
    //left pehle
    leftMax[0]=arr[0];
    for(int i=1;i<n;i++){
        leftMax[i]=max(leftMax[i-1],arr[i]);
    }

    //right
    rightMax[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        rightMax[i]=max(rightMax[i+1],arr[i]);
    }

    long long res=0;
    for(int i=0;i<n;i++){
        long long water=min(leftMax[i],rightMax[i]) -arr[i];
        res+=water;
    }
    return res;
}

//optimal (2 pointer)
//intuition: https://www.youtube.com/watch?v=m18Hntz4go8&ab_channel=takeUforward
long long getTrappedWater(long long* arr, int n) {
    // Write your code here.
    int l=0;
    int r=n-1;
    long long res=0;
    long long leftMax=0;
    long long rightMax=0;

    while(l<=r){
        if(arr[l]<=arr[r]){
            //means right mai koi support karega hume lessgo for sure
            if(arr[l]>=leftMax) leftMax=arr[l];
            else res+=(leftMax-arr[l]);
            l++;
        }
        else{
             if(arr[r]>=rightMax) rightMax=arr[r];
            else res+=(rightMax-arr[r]);
            r--;
        }
    }
    return res;
}
