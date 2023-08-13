//link:https://leetcode.com/problems/set-mismatch/submissions/

   vector<int> findErrorNums(vector<int>& arr) {
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
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(arr[i]-1!=i){
                //arr[i] duplicate coz kisi aur ki jagah pe ghus gya
                ans.push_back(arr[i]);

                //ith index ne ghusne diya kyuki uska correct element mila hi nahi
                
                ans.push_back(i+1);
                return ans;
            }
        }
        return ans;
    }