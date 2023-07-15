//consider every block as the height of that rectangle
//find the 1st smaller element on right and left then (right-left+1) to get width * height
//but this is of O(n^2)

//brute code (passes all cases)
 int largestRectangle(vector < int > & heights) {
   // Write your code here.
   int n=heights.size();
   int res=0;
   for(int i=0;i<n;i++){
     int curr_height=heights[i];
     //now find left and right boundary
     int left=0;
     int right=n-1;
     for(int j=i-1;j>=0;j--){
       if(heights[j]<curr_height){
         left=j+1;
         break;
       }
     }
     for(int k=i+1;k<n;k++){
       if(heights[k]<curr_height){
         right=k-1;
         break;
       }
     }
     int width=right-left+1;
     res=max(res,curr_height*width);
   }
   return res;
 }