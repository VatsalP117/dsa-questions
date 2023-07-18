//BASICALLY NEXT SMALLER ON LEFT AND NEXT SMALLER ON RIGHT HI HAI BHAI

 #include <bits/stdc++.h>
 int largestRectangle(vector < int > & heights) {
   // Write your code here.
   int n=heights.size();//number of building
   vector<int> leftSmaller(n); //we will store next smaller element on left ka index for each element
   vector<int> rightSmaller(n); ////we will store next smaller element on right ka index for each element
  stack<int> st;//stores indexes
    //lets find leftSmaller first
    for(int i=0;i<n;i++){
      //since we want next smaller stack mai jitne bade elements sabko bhagao
      while(st.empty()==false && heights[st.top()]>=heights[i]){
        st.pop();
      }
      if(st.empty()){
        //means no smaller element on the left
        leftSmaller[i]=-1; //ground (psuedoindex)
      }
      else{
        leftSmaller[i]=st.top();
      }
      st.push(i);
    }

    //do same to find rightsmaller now
    while(!st.empty()) st.pop(); //clear stack for next use

    for(int i=n-1;i>=0;i--){
      while(st.empty()==false && heights[st.top()]>=heights[i]){
        st.pop();
      }
      if(st.empty()){
        //no one smaller on right
        rightSmaller[i]=n; //ground
      }
      else{
        rightSmaller[i]=st.top();
      }
      st.push(i);
    }
    int maxi=0;
    for(int i=0;i<n;i++){
      int width=rightSmaller[i]-leftSmaller[i]-1;
      maxi=max(maxi,width*heights[i]);
    }
    return maxi;
 }