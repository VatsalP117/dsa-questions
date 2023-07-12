//NO DUPLICATE VALUES
int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==k) return mid;
        
        //atleast one of right or left half will be sorted
        //check if left half is sorted
        if(arr[low]<=arr[mid]){
            //it is sorted on left!
            //now check if our target lies in that range
            if(arr[low]<=k && arr[mid]>=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
        }
        //check if right half is sorted
        else if(arr[mid]<=arr[high]){
            //check if in correct range
            if(arr[mid]<=k && arr[high]>=k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1;
}