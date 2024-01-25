//same question is one leetcode under 2 titles
//leetcode 316: remove duplicated letters
//leetcode 1081: smallest subsequence of distincy characters

class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        stack<char> st;
        vector<int> freq(26,0);
        vector<bool> seen(26,false);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        // cout<<freq['o'-'a']<<endl;
        for(int i=0;i<n;i++){
            //idea is to maintain an increasing order of elements
            //so we pop everyone from stack jo apne se bada hai(jyuki bade ke baad chota aayega to kaisa order bhai)
            //but theres a catch=> what is the fella we removed never comes again in the string? i.e what is vo uska only occurence ho? to we dont pop if thats the case
            //freq[any char] at any point just says AUR KITNI BAAR AAYEGA ye aage
            //basically pop ke pehle dekho vapas ye future mai aayega to sahi na
            
            if(seen[s[i]-'a']==true) {
                //already included in stack so dont process it
                freq[s[i]-'a']--;
                continue;
            }
            while(!st.empty() && st.top()>s[i] && freq[st.top()-'a']>0){
                seen[st.top()-'a']=false;
                st.pop();
            }     
            st.push(s[i]);
            seen[s[i]-'a']=true;
            freq[s[i]-'a']--;

            }
            string res="";
        cout<<st.size()<<endl;
        while(!st.empty()){
            res+=(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};