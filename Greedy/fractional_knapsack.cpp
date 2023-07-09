#include <bits/stdc++.h> 
struct Item{
    int weight;
    int value;
};
static bool cmp(pair<double,Item> a,pair<double,Item> b){
    return a.first>b.first;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
   
    vector<pair<double,Item>> v;
    for(auto it:items){
        int wt=it.first;
        int val=it.second;
        double ratio=(double)val/wt;
        Item i;
        i.value=val;
        i.weight=wt;
        v.push_back({ratio,i});
    }
    sort(v.begin(),v.end(),cmp);
    double res=0;
    for(auto it:v){
        if(w==0) break;
        int wt=it.second.weight;
        int val=it.second.value;
        if(wt<=w){
            res+=val;
            w=w-wt;
        }
        else{
            res+=(double)w*it.first;
            w=0;
        }
    }
    return res;
    
}