//linK:https://leetcode.com/problems/fruit-into-baskets/
//basically two conditions:
//1st: can only pick consecutive fruits
//2nd: only 2 types of fruits allowed not more than that


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int i=0;
        int j=0;
        int res=0;
        int count=0;
        unordered_map<int,int> um;
        while(j<n){
            um[fruits[j]]++;
            if(um[fruits[j]]==1){
                //means new type of fruit taken
                count++;
            }
            //check if overshoots
            if(count>2){
                while(count>2){
                    um[fruits[i]]--;
                    if(um[fruits[i]]==0) count--;
                    i++;
                }
            }
            if(count<=2){
                res=max(res,j-i+1);
            }
            j++;
            

        }
        return res;
    }
};