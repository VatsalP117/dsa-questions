//link:https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/
class Solution {
public:
    int operateOn(int num1,int num2,string op){
        if(op=="+"){
            return num1+num2;
        }
        if(op=="-"){
            return (num2-num1);
        }
        if(op=="*"){
            return num2*num1;
        }
        if(op=="/"){
            return num2/num1;
        }
        return 1;
    }
    bool isOperator(string ch){
        return ch=="+" || ch=="-" || ch=="*" || ch=="/";
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n=tokens.size();
        for(int i=0;i<n;i++){
            if(isOperator(tokens[i])){
                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();
                int res=operateOn(num1,num2,tokens[i]);
                st.push(res);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};