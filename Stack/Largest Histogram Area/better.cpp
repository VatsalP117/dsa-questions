//same as brute but optimized way of finding left/right smaller
 #include <bits/stdc++.h>
 int largestRectangle(vector < int > & heights) {
   // Write your code here.
   int n=heights.size();
   vector<int> leftSmaller(n,0);
   vector<int> rightSmaller(n,n-1);
   stack<int> st; //we are storing elements in increasing order like 1 4 6(top)
   for(int i=0;i<n;i++){
     int curr_height=heights[i];
     if(st.empty()){
       //means no smaller on the left so boundary on left=0
       //alread is zero so litr
       st.push(i);
       continue;
     }
     while(!st.empty() && heights[st.top()]>=curr_height){
       //agar left mai curr height se chota aagya to dikkat hai
       st.pop();
     }
     
     if(!st.empty()){
       //means no element on left is smaller so no bt left boundary=0
       leftSmaller[i]=st.top()+1;
     }
     st.push(i);     
   }
    //clear stack for next use
    while(!st.empty()) st.pop();
     for(int i=n-1;i>=0;i--){
     int curr_height=heights[i];
     if(st.empty()){
       //means no smaller on the left so boundary on left=0
       //alread is zero so litr
       st.push(i);
       continue;
     }
     while(!st.empty() && heights[st.top()]>=curr_height){
       //agar left mai curr height se chota aagya to dikkat hai
       st.pop();
     }
     
     if(!st.empty()){
       //means no element on left is smaller so no bt left boundary=0
       rightSmaller[i]=st.top()-1;
     }
     st.push(i);     
   }
   int res=0;
   for(int i=0;i<n;i++){
     res=max(res,heights[i]*(rightSmaller[i]-leftSmaller[i]+1));
   }
   return res;
 }