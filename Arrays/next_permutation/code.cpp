vector<int> nextGreaterPermutation(vector<int> &A) {
    // Write your code here.
    int ind=-1; //index of break point
    int n=A.size();
    for(int i=n-2;i>=0;i--){
        if(A[i]<A[i+1]){
            ind=i;
            break;
        }
    }
    //found the breakpoint now
    if(ind==-1){
        //no dip or breakpoint
        reverse(A.begin(),A.end());
        return A;
    }

    //find the next greater element
    for(int i=n-1;i>ind;i--){
        if(A[i]>A[ind]){
            swap(A[i],A[ind]);
            break;
        }
    }
    //sort (or reverse is same in this case since in decreasing order) the rest
    reverse(A.begin()+ind+1,A.end());
    return A;
}