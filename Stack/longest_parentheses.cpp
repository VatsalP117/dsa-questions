https://leetcode.com/problems/longest-valid-parentheses/solutions/3401956/100-detailed-explaination-with-pictures-o-n-in-c-java-python-stack/
int longestValidParentheses(string s) {
        int n=s.size();
        stack<int> st;
        int res=0;
        //stack stores indexes of all opening brackets jisko koi saathi nahi mila
        //if you see closing bracket,pop from stack
        //then the index of top will be jisko saath nahi mila aur uske baad wale sab paired
        //so length = curr_index-top
        st.push(-1);//incase entire string is valid
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            //else if closing bracket to find a match
            else{
                if(st.size()==1){
                    //means pnly -1 inside and no ( found yet
                    st.top()=(i);     
                    //ab isko match kabhi nahi milega so just keep it a top
                    //means closing brackets have dominated opening         
                }
                else{
                    st.pop(); //iska match ho gya to konse index tk everyone matched? the index after that st.top wala
                    res=max(res,i-st.top());
                }
            }
        }
        return res;
    }