//only 1 peak
int findPeakElement(vector<int> &arr) {
   //ONLY 1 PEAK (to understand the algo but works for multiple peaks as well if we gotta return any one peak)
   //when you trim down searc spaces, you will end up in a space wih only one peak
   //VISUALIZE ULTA V WALA GRAPH FIRST RISES TO PEAK THEN DOWNWARD SLOPE
  int n=arr.size();
        if(n==1) return 0;
        if(arr[0]>arr[1]) return 0;
        if(arr[n-1]>arr[n-2]) return n-1;
        int low=1;
        int high=n-2;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
            else if(arr[mid-1]>arr[mid]){
                //you are on the right side of peak (peak ke baad wale downward slope pe)
                high=mid-1;
            }
            else{
                //for multple peaks keep this else only and not else if coz if you are in ulta peak (V) none of the elif will happen but you can move to either way and find peak
                //arr[mid+1]>arr[mid] means you are on left of peak (upward slope)
                low=mid+1;
            }
        }
        return -1;
}