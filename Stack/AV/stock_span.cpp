#include <bits/stdc++.h>
vector<int> findStockSpans(vector<int>& prices) {
    // Write your code here.
   
   //basically NEAREST LEFT GREATER ELEMENT NIKAL RAHE H
   int n=prices.size();
   vector<int> ans(n);
   stack<int> st;
   for(int i=0;i<n;i++){
       
       //apne ko previous(left) greater element chaiye
       //so remove all those which are smaller or requal to current element
       while(st.empty()==false && prices[st.top()]<prices[i]){
           st.pop();
       }
       if(st.empty()){
           //meeans no element on left is greater
           ans[i]=i+1;
       }
       else{
           ans[i]=i-st.top();
       }
       st.push(i);
   }
   return ans;
}