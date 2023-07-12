//iterative
int search(vector<int>& nums, int target) {
    // Write Your Code Here
    int n=nums.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

//recursive
int f(int low,int high,int target,vector<int> &nums){
    if(high<low){
        return -1;
    }
    int mid=(low+high)/2;
    if(nums[mid]==target){
        return mid;
    }
    else if(nums[mid]>target){
        //search space on the left
        return f(low,mid-1,target,nums);
    }
    else{
        return f(mid+1,high,target,nums);
    }
}
int search(vector<int>& nums, int target) {
    // Write Your Code Here
    int n=nums.size();
    return f(0,n-1,target,nums);
}