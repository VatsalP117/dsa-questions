//link:https://www.codingninjas.com/studio/problems/longest-substring-with-at-most-k-distinct-characters_2221410?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1
#include <bits/stdc++.h>
int kDistinctChars(int k, string &str)
{
    // Write your code here
    int n=str.size();
    int res=0;
    unordered_map<char,int> um;
    int i=0;
    int j=0;
    int count=0;
    while(j<n){
        //calculations
        um[str[j]]++;
        if(um[str[j]]==1){
            //means ye naya char aaya
            count++;
        }
        //check if overshoots
        if(count>k){
            while(count>k){
                um[str[i]]--;
                if(um[str[i]]==0){
                    count--;
                }
                i++;
            }
        }
        if(count<=k){
            res=max(res,j-i+1);
        }
        j++;
    }
    return res;
}


