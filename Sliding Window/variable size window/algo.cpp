//POSITIVES ONLY
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n=a.size();
    int i=0;
    int j=0;
    long long sum=0;
    int res=0;
    while(j<n){
        sum+=a[j];
        //approach: always stay in the range<k and try to reach k
        //if you overshoot, remove elements by i++ and again try to reach in <=k range
        //sum se aage chale gaye to vapas aa jao
        //vapas kaise? aage ke elemnts hatake
        if(sum>k){
            while(sum>k){
            sum=sum-a[i];
            i++;
            }
        }
        if(sum==k){
            res=max(res,j-i+1);
        }
        //j to humesha badhega
        j++;
        
    }
    return res;
}