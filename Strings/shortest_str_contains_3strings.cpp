//link: https://leetcode.com/problems/shortest-string-that-contains-three-strings/submissions/
//return string that contains all 3 strings as substrings

//Merge function is the main essence of this question
class Solution {
public:
   void checkMin(string str,string &ans){
        if(str.size()<ans.size()){
            ans=str;
        }
        else if(str.size()==ans.size() && str<ans){
            ans=str;
        }
    }
    string merge(string a,string b){
        if(a.find(b)!=string::npos){
            return a;
            //since b is already a substring of a
        }
        //now try to find such that largest suffix of a ==largest prefix of b
        int n=a.size();
        int m=b.size();
        int i=n-1;
        int j=0;
        int index=0;
        while(i>=0){
            //we are comparing suffix substr of a with prefix substr of b
            //if at index i, length of suffix substr of a =n-i
            if(a.substr(i)==b.substr(j,n-i)){
                index=j+n-i;
                //since itni to match ho gayi to iske baad ki string hi lenge b se
            }
            i--;
        }
        return a+b.substr(index);
    }
 
    string minimumString(string a, string b, string c) {
        string ans=a+b+c;
        //now try all permutations
        checkMin(merge(merge(a,b),c),ans);
        checkMin(merge(merge(a,c),b),ans);
        checkMin(merge(merge(b,a),c),ans);
        checkMin(merge(merge(b,c),a),ans);
        checkMin(merge(merge(c,a),b),ans);
        checkMin(merge(merge(c,b),a),ans);
        return ans;
    }
};