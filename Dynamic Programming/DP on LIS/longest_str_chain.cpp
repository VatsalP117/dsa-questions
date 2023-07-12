class Solution {
public:
   
bool compare(string &longer,string &shorter){
    int n=longer.size();
    int m=shorter.size();
    if(n-m!=1) return false;
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(longer[i]==shorter[j]){
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    if(j==m) return true;
    else return false; 
}
static bool cmp(string &s,string &t){
    return s.size()<=t.size();
}
    int longestStrChain(vector<string>& arr) {
            int n=arr.size();
    sort(arr.begin(),arr.end(),cmp);
    vector<int> dp(n,1);
    int maxi=1;
    for(int i=1;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(compare(arr[i],arr[prev])){
                dp[i]=max(dp[i],1+dp[prev]);
            }
        }
        maxi=max(maxi,dp[i]);
    }
    return maxi;
    }
};