int Solution::diffPossible(vector<int> &arr, int B) {
    int n=arr.size();
    int left=0;
    int right=0;
    while(right<n){
        if(left==right){
            right++;
        }
        else{
            int diff=arr[right]-arr[left];
            if(diff==B) return 1;
            else if(diff<B){
                //gotta increase diff
                right++;
            }
            else{
                //need to decrease difference
                left++;
            }
        }
    }
    return 0;
}