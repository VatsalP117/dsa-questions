//leetcode 11

// Idea
// The strategy is to start with the container of the longest width and move the sides inwards one by one to see 
// if we can get a larger area by shortening the width but getting a taller height. But how do we know which side to move?

// The key insight here is that moving the longer side inwards is completely unnecessary because the height of the water is bounded by the shorter side.
//  In other words, we will never be able to get a greater area by moving the longer side inwards because the height will either stay the same or get shorter, and the width will keep decreasing.

// So we can skip all those calculations and instead move the shorter side inwards. This way, we might get a taller height and a larger area.
//  So at each step, we calculate the area then move the shorter side inwards. When the left and right sides meet, we are done and we can return the largest area calculated so far.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int res=0;
        int i=0;
        int j=n-1;
        while(i<j){
            int h;
            if(height[i]==height[j]){
                h=height[i];
            }
            else h=min(height[i],height[j]);
            cout<<h<<endl;
            res=max(res,h*(j-i));
            //ab aage piche kaise?
            //apna bottleneck kon hai? jp chota hai wahi na to usko aage badhao
            if(height[i]==h)i++;
            else j--;
        }
        return res;
    }
};