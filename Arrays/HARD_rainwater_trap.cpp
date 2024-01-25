//leetcode 42
class Solution {
public:
    int trap(vector<int>& height) {
        //two pointer approach
        int n=height.size();
        int left=0;
        int right=n-1;
        int leftMax=0;
        int rightMax=0;
        int res=0;
        while(left<=right){
            //2 cases possigle here
            if(height[left]<=height[right]){
                //now we know that someone on the right is there for sure to bound water for us
                //why? bhai iski if condition kya hai vo to dekh
                //now the questionis there someone on the left to do so as well?
                if(height[left]>=leftMax){
                    //means apne se bada koi nahi hai sadly :(
                    leftMax=height[left];
                }
                else{
                    res+=(leftMax-height[left]);
                    //how do we know this for sure?
                    //we only increase left pointer when height[left]<=height[right]

                    //that means leftMax right wali chota hi hoga
                    //so leftMax ki value hi apne kaam ki hai right kint abhi bada ho hum paani leftMax se                  zyada height pe to rakh nahi sakte na dost                    
                }
                left++;
            }
            else{
                if(height[right]>=rightMax){
                    //means apne se bada koi nahi hai sadly :(
                    rightMax=height[right];
                }
                else{
                    res+=(rightMax-height[right]);
                    
                }
                right--;
            }
        }
        return res;
    }
};