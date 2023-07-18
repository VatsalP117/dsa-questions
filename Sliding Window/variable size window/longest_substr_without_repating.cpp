//https://www.codingninjas.com/studio/problems/longest-substring-without-repeating-characters_630418?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1
//standard format
#include <bits/stdc++.h> 
int uniqueSubstrings(string str)
{
    //Write your code here
    int n=str.size();
    int res=0;
    int i=0;
    int j=0;
    unordered_set<char> s;
    while(j<n){
        if(s.find(str[j])!=s.end()){
            //duplicates found
            while(s.find(str[j])!=s.end()){
                s.erase(str[i]);
                i++;
            }
        }
        //duplicates ka bt sorted so now
        //mast naya element hai ye to
        s.insert(str[j]);
        res=max(res,j-i+1);
        
        j++;
    }
    return res;
}

//humesha agar j++ ahi karna to varna same hi chiz h
#include <bits/stdc++.h> 
int uniqueSubstrings(string str)
{
    //Write your code here
    int n=str.size();
    int res=0;
    int i=0;
    int j=0;
    unordered_set<char> s;
    while(j<n){
        if(s.find(str[j])==s.end()){
            //naya unique character aaya hai guys
            s.insert(str[j]);
            res=max(res,j-i+1);
            j++;
        }
        else{
            //duplicate found
            s.erase(str[i]);
            i++;
            
            
        }
        
    }
  