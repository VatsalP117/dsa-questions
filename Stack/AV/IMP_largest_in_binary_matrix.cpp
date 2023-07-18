//basically MAH WAS FOR 1D ARRAY THIS IS 2D
//WE WILL USE MAH CODE ONLY AFTER CONVERTING 2D TO 1D (intuition: must watch video of aditya verma)

#include <bits/stdc++.h>
int mah(vector < int > & heights) {
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
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	// Write your code here.
	//n=number of rows (inte hisograms banenge mah mai daalne)
	//m=number of columns 
	int res=0;
	vector<int> arr(m,0);
	for(int i=0;i<n;i++){
		//lets create an historgram using 1st row only now
		
		for(int j=0;j<m;j++){
			if(mat[i][j]==1){
				arr[j]++;
			}
			else{
				arr[j]=0;//coz hawa mai nahi udegi
			}
		}
	res=max(res,mah(arr));
	}
	return res;
}