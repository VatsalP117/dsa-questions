vector<int> Solution::solve(vector<int> &A) {
     int low=-1;
   
    for(int i=0;i<A.size();i++){
        if(A[i]==0){
            low++;
            swap(A[low],A[i]);
        }
    }
    return A;
}