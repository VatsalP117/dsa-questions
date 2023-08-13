//link: https://leetcode.com/problems/find-the-duplicate-number/submissions/
//numbers from [1,n] and only one duplicate
//again exact same algo hai

int findDuplicate(vector<int>& arr) {
         int n=arr.size();
        int i=0;
        while(i<n){
            int correctIndex=arr[i]-1;
            //move ahead if correct ya fir ye element ka setting kar rakha h pehle se
            if(arr[i]!=arr[correctIndex]){
                
                swap(arr[i],arr[correctIndex]);
               
            }
            else{
                 i++;
            }
        }
        //now all the elements will be at the correct position
        //jo number 2 baar aaya hoga vo ek galat position pe bhi hoga coz correct position to ek hi hai
        //bo hua apna ans
        for(int i=0;i<n;i++){
            if(arr[i]-1!=i){
                return arr[i];
            }
        }
        return n;
    }

