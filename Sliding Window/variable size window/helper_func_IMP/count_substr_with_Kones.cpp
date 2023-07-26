//basically telll number of substrs that have exactly k one;s
//helper teel snumber of substrs with number of ones<=k
#include <bits/stdc++.h> 
#include<unordered_set>
int helper(string &s, int k){
        int count=0;
    int res=0;
    int n=s.size();
    int i=0;
    int j=0;
    
    while(j<n){
        if(s[j]=='1') count++;

        if(count>k){
            while(count>k){
                if(s[i]=='1'){
                    count--;
                }
                i++;
            }
        }
        if(count<=k){
           res+=j-i+1;
        }
        j++;
    }
    return res;
}
int countSubstr(string &s, int k) {
    // Write your code here.
    return helper(s,k)-helper(s,k-1);

}