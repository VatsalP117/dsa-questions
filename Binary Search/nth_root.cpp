int f(int mid,int n,int m){
  //important to prevent overflow
  //coz say 1e9 raise to 10 de diya to gaye
  //return 1 if equal to m
  //return 0 if <m
  //return 2 is >m
  long long ans=1;
  for(int i=1;i<=n;i++){
    ans=ans*mid;
    if(ans>m) return 2;
  }
  if(ans==m) return 1;
  else return 0;
}
int NthRoot(int n, int m) {
  // Write your code here.
  
  int low=1;
  int high=m;
  while(low<=high){
    int mid=(low+high)/2;
    int judgement=f(mid,n,m);
    if(judgement==1) return mid;
    else if(judgement==0){
      low=mid+1;
    }
    else{
      high=mid-1;
    }

  }
  return -1;
}