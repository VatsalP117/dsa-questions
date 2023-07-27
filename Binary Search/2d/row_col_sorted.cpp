//link: https://leetcode.com/problems/search-a-2d-matrix-ii/
//best explaination: https://www.youtube.com/watch?v=VS0BcOiKaGI&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=20
We start from top right corner and will always go in right direction towards our answer 
islie aisa nah hoga hi aage chale gaye fir ans ke liye vapas ghum ke aaye 
na, har ek step ans ke taraf right direction mai lenge 
worst case: ans bottom left corner mai nikla so all rows+cols traverse 
therefore TC=O(n+m)
YT video is legit best ever so watch once and 100% clarity is guaranted 
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0;//1st row
        int j=n-1;//last col
        //starting at top right corner
        while(i<m && j>=0){
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]>target){
                //do option hai ya to left mai jao ya niche jao
                //nihce to aur bade elements ho isse bhi aur yahi target se bada hai
                //to niche to nahi jaana, left mai chote elements honge
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }