//link: 

class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n=arr.size();
        //we have to return smallest positive number right?
        int i=0;
        //negative aur >n walo ko lite le lenge
        while(i<n){
            if(arr[i]<=0 || arr[i]>n){
                // if(arr[i]<=0) arr[i]=-1;
                //ye line upar wali not needed but for one case very large negative number tha to overflow happening
                i++;
            }
            else{
                int correctIndex=arr[i]-1;
                if(arr[i]!=arr[correctIndex]){
                    swap(arr[i],arr[correctIndex]);
                }
                else{
                    i++;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]-1!=i){
                return i+1;
            }
        }
        return n+1;
        
    }
};