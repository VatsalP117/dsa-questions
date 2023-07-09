//difference btw maximimum and minimum choclates given is minimum
//https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
 long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(),a.end());
        long long res=INT_MAX;
        int i=0;
        int j=m-1;
        while(j<n){
            long long diff=a[j]-a[i];
            res=min(res,diff);
            i++;
            j++;
        }
        return res;
    
    } 