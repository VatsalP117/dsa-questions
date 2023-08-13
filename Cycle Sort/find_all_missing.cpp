//link:https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 vector<int> findDisappearedNumbers(vector<int>& arr) {
   
        int n=arr.size();
        int i=0;
        while(i<n){
            int correctIndex=arr[i]-1;
            //move ahead if correct ya fir ye element ka setting kar rakha h pehle se
            if(correctIndex==i || arr[correctIndex]==arr[i]){
                //second condition if we have already found this element before and usko humne set kar diya h
                //otherwise infinite loop mai chale jayega
                i++;
            }
            else{
                swap(arr[i],arr[correctIndex]);
            }
        }
        vector<int> ans;
        //if there was number belonginf to that index,it would be there now
        //if not, it is missing
        for(int i=0;i<n;i++){
            if(arr[i]-1!=i){
                ans.push_back(i+1);
            }
        }
        return ans;
    }

//same logic but a better implementation 
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& arr) {
   
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
        vector<int> ans;
        //if there was number belonginf to that index,it would be there now
        //if not, it is missing
        for(int i=0;i<n;i++){
            if(arr[i]-1!=i){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};