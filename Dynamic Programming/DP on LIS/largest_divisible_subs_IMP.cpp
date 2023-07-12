#include <bits/stdc++.h> 
vector<int> divisibleSet(vector<int> &arr){
    // Write your code here.
    int n=arr.size();
    sort(arr.begin(),arr.end());
    //subset so order does not matter
    //now find LONGEST DIVISBLE SUBSEQUENCE
    //[1,4,8] and new ele is 16, just check if 16%8=0 since sorted order mai hai 4,1 would divide as well
    
    //first find length
    vector<int> dp(n,1);
    vector<int> back(n);
    for(int i=0;i<n;i++) back[i]=i;
    //since initially all are individual subsequence themselves
    
    int length=1;
    for(int i=1;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(arr[i]%arr[prev]==0){
                if(dp[i]<1+dp[prev]){
                    dp[i]=1+dp[prev];
                    back[i]=prev;
                }
            }
        }
      length=max(length,dp[i]);  
    }
    int lastIndex=-1;
    for(int i=0;i<n;i++){
        if(dp[i]==length){
            lastIndex=i;
            break;
        }
    }
    //now start backtracking to find ans
    vector<int> ans(length,-1);
    ans[length-1]=arr[lastIndex];
    length--;
    lastIndex=back[lastIndex];
    while(back[lastIndex]!=lastIndex &&length>=1){
        ans[length-1]=arr[lastIndex];
        length--;
        lastIndex=back[lastIndex];
    }
    return ans;
}