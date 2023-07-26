//https://leetcode.com/problems/asteroid-collision/
//yt:https://www.youtube.com/watch?v=LN7KjRszjk4

    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(st.empty() || asteroids[i]>0){
                st.push(asteroids[i]);
            }
            //if stack is empty no tension sidha push
            //also for +ve (right moving) also just push
            //when there is a negative(left) we will see if it can destroy
            //all these +ve nodes we have pushed. 
            else if(asteroids[i]<0){
                //now check for collision
                while(st.empty()==false && st.top()>0 && abs(asteroids[i])>st.top()){
                    st.pop();
                }
                //so this asteroid has destroyed has all opposite nodes smaller than itself
                //if now we have same size node just remove it and current will be destroyed as well
                if(st.empty()==false && st.top()+asteroids[i]==0){
                    st.pop();
                }
                else if(st.empty() || st.top()<0){
                    //means this was the most powerful node till now and it survived
                    st.push(asteroids[i]);
                }
            }
           
           
        }
        while(!st.empty()){
               ans.push_back(st.top());
               st.pop();
           }
           reverse(ans.begin(),ans.end());
        return ans;
    }