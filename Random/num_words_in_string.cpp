int Solution::solve(string A) {
    int count=0;
    int n=A.size();
    int start=0;
    while(A[start]==' ') start++;
    int end=n-1;
    while(A[end]==' ') end--;
    for(int i=start;i<=end;i++){
        if(i==end || (A[i]==' ' && A[i+1]!=' ')) count++;
    }
    return count;
    
}