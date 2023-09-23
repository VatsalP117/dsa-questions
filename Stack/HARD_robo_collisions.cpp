//link:https://leetcode.com/contest/weekly-contest-351/problems/robot-collisions/
//hard to nahi hai it was clickbait
//par definetly implementation heavy with my approach (coz positions are not sorted and sort karna padega solve karne)
// aur ans return karna h in the order of given input unsorted array to vo bt de diya thoda

typedef pair<int,pair<char,pair<int,int>>> pp;
class Solution {
public:
    
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pp> robots;//stores {position,{direction,health}}
        int n=positions.size();
        for(int i=0;i<n;i++){
            robots.push_back({positions[i],{directions[i],{healths[i],i}}});
        }
        sort(robots.begin(),robots.end());
        stack<pp> st;
        for(auto it:robots){
            int pos=it.first;
            char dir=it.second.first;
            int health=it.second.second.first;
            int index=it.second.second.second;
            if(dir=='R'){
                st.push(it);
                continue;
            }
            else{
                //left wala robot mila to ye bhidega 
                while(st.empty()==false && st.top().second.first!=dir && health>0){
                    auto opp=st.top();
                    if(opp.second.second.first>health){
                        //apna to game over lmao
                        health=0;
                        st.top().second.second.first--;
                    }
                    else if(opp.second.second.first<health){
                        st.pop();
                        health--;
                    }
                    else{
                        //equal case to dono gaye
                        st.pop();
                        health=0;
                    }
                    
                }
                if(health>0){
                    st.push({pos,{dir,{health,index}}});
                }
            }
        }
        vector<pair<int,int>> ans;
        while(!st.empty()){
            ans.push_back({st.top().second.second.second,st.top().second.second.first});
            st.pop();
        }
        sort(ans.begin(),ans.end());
        vector<int> res;
        for(auto it:ans){
            res.push_back(it.second);
        }
        
        return res;
        
    }
};
