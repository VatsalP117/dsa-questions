https://leetcode.com/problems/count-lattice-points-inside-a-circle/
class Solution {
public:
    bool check(int x,int y,vector<int> &c){
        return (pow(x-c[0],2)+pow(y-c[1],2)-pow(c[2],2))<=0;
    }
    void find_points(vector<int> &c,set<pair<int,int>> &s){
        for(int x=c[0]-c[2];x<=(c[0]+c[2]);x++){
            for(int y=c[1]-c[2];y<=(c[1]+c[2]);y++){
                if(check(x,y,c)){
                    s.insert({x,y});
                }
            }
        }
    }
    int countLatticePoints(vector<vector<int>>& circles) {
        int n=circles.size();
        set<pair<int,int>> s;//to store all points that we have already counted
        for(auto &it:circles){
            find_points(it,s);
            //this function find all points inside this (aur set mai daalega to no worry of duplication)
            
        }
        return s.size();
    }
};