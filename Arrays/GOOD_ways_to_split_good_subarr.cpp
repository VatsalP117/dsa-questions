//link:https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/description/

// Approach
// eg1:
//     arr=0 1 [0 0 0 0] 1 0
//     jo left most aur right most 0 hai unke paas to ek hi option hai, side wale 1 se combine ho jao
//     vo [] ke andar 0 hai unke paas hai lekin options
//     ya to saare 4 left wali gang mai, ya 3, ya 2,1 ya 0 => so 5 ways to decide vo 4 zero konsi taraf jayenge 
//     so 5 ways to split 
// eg2:
//     arr= 0 1 [0 0 0] 1 [0 0 0 0] 1 0
//     ways =(3+1)*(4+1)= 20
        // i.e focus on only those 0's jo koi bhi do one's ke bich mai hai

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n=nums.size();
        long ans=0;
        int oneCount=0;
        int currZeros=0; //bich wale zero count karne
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                currZeros++;
            }
            else{
                oneCount++;
                if(oneCount==1){
                    ans=1;
                    //since pehle 1 mila abhi to
                }
                else{
                    ans=(ans*(currZeros+1)%mod)%mod;
                }
                currZeros=0;
            }
        }
        return ans;
    }
};