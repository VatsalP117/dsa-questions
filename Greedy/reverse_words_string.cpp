//https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1
class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        string ans="";
        string temp="";
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            if(s[i]=='.'){
                reverse(temp.begin(),temp.end());
                ans+=temp;
                ans+=".";
                temp="";
            }
            else{
                temp+=s[i];
            }
        }
        reverse(temp.begin(),temp.end());
        ans+=temp;
        return ans;
    } 
};
