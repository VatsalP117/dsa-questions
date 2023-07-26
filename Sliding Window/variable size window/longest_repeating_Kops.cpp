//thoda brute since find max freq iS O(26)
//number of operations required= length of window - count of freq of most occuring character (since baakiyo ko udana padega)
class Solution {
public:
    int find_max_freq(unordered_map<char,int> &um){
        int max_freq=0;
            for(auto it:um){
                if(it.second>max_freq) max_freq=it.second;
            }
        return max_freq;
    }
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int> um;
        int res=0;
        int maxi=0;
        int i=0;
        int j=0;
        while(j<n){
            um[s[j]]++;
           
            if((j-i+1)-find_max_freq(um)>k){
                while(((j-i+1)-find_max_freq(um))>k){
                    um[s[i]]--;
                    i++;
                }
            }
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};