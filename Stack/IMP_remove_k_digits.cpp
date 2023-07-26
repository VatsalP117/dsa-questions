//link:https://leetcode.com/problems/remove-k-digits/submissions/
//https://www.youtube.com/watch?v=3QJzHqNAEXs

Idea: if you are given 4 digits, to get the least number made by them arrange them in increasing order
so 4325 diya hai to arrange as : 2345 i.e graph of these numbers is always increasing (or can stay the same)
so here also do the same, as and when there is a dip in the graph, vo bade number ko hata do
so that graph will be flattend/increasing graph
jo dip jitna pehle aayi usko bhagane ka importance zyada since pehle ki dip willincrease the overall number of a lot
and also if ans="0200" then we gotta return 200 so last mai kaafi jo code vo bas ye karne hai 
also what if input is 123 and k=1, since always increasing so  no dip so just remove elements from top(largest) till you have removed k elements


string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.size();
      
        if(k==n) return "0";
        string ans="";
        for(int i=0;i<n;i++){
            if(st.empty()|| st.top()<=num[i]){
                st.push(num[i]);
            }
            else if(st.top()>num[i]){
                //means dip aaya
                while(st.empty()==false && k>0 && st.top()>num[i]){
                    st.pop();
                    k--;
                }
                
                st.push(num[i]);
                
               
            }
        }
        //this is for the always increasing case where we failed to remove k elements
        while(st.empty()==false && k>0){
            k--;
            st.pop();
        }

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        //rest of the code is just to remove leading zeros
        string res="";
        bool flag=false;
        for(int i=0;i<ans.size();i++){
            if(flag){
                res+=ans[i];
            }
            else{
                if(ans[i]!='0'){
                    flag=true;
                    res+=ans[i];
                }
            }
        }
        if(res=="") return "0";
        return res;
      
    }