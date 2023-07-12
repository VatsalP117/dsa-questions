//DUPLICATE VALUES
//WHY PREV ALGO WONT WORK?
//eg arr=[3,1,2,3,3,3,3];
//arr values of low=mid=high=3. kaise decide karoge konna sorted?
//so we need to trim down our condition to check which half is sorted
//go arounf this condition: arr[mid]==arr[low]==arr[high]//
//we know arr[mid is not target so arr[low] and arr[high] wont be target either so trim down search space
//low-- and high--
//baki sab same
bool searchInARotatedSortedArrayII(vector<int>&arr, int key) {
    // Write your code here.
    int n=arr.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==key){
            return true;
        }
        
        //edge case 
        if(arr[mid]==arr[low] && arr[mid]==arr[high]){
            //arr[mid] is not equal to key so neither will low and high be
            low++;
            high--;
        }
        else if(arr[mid]>=arr[low]){
            //left half sorted
            if(arr[mid]>=key && arr[low]<=key){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else if(arr[mid]<=arr[high]){
            if(arr[mid]<=key && arr[high]>=key){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return false;
}

