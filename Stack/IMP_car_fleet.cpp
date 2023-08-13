//link: https://leetcode.com/problems/car-fleet/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        int n=position.size();
        for(int i=0;i<n;i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end());
        //first sorted by position
        stack<double> st;
        for(auto it: cars){
            double time_req=double(target-it.first)/it.second;
            //time req is basically remaining distance by speed
            //we are pushing time req to the stack
            while(st.empty()==false && st.top()<=time_req){
                //elemenst in stack are behind our car
                //if they need less time than us means they will catch us up at some point (since piche h fir bhi jaldi pahochna h unhe)
                //so they we will limited by our car so just part of our fleet so pop them
                st.pop();
            }
            st.push(time_req);
        }
        return st.size();
    }
};