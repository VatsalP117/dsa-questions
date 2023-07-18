//good to understand the concept and general format
//https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
    int longestKSubstr(string s, int k) {
    // your code here
    unordered_map<char,int> um;
    int count=0;
    int i=0;
    int j=0;
    int n=s.size();
    int res=-1;
    while(j<n){
        //calculations
        um[s[j]]++;
        if(um[s[j]]==1){
            //means ek naya distinct character mila
            count++;
        }
        //conditions
        if(count==k){
            res=max(res,j-i+1);
        }
        
        //overshooting count
        else if(count>k){
            while(count>k){
                um[s[i]]--;
                if(um[s[i]]==0){
                    count--;
                }
                i++;
            }
        }
        
        j++;
        
    }
    return res;
    }

//alternate
class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    unordered_map<char,int> um;
    int count=0;
    int i=0;
    int j=0;
    int n=s.size();
    int res=-1;
    while(j<n){
        //calculations
        if(count>k){
            while(count>k){
                um[s[i]]--;
                if(um[s[i]]==0){
                    count--;
                }
                i++;
            }
        }
        um[s[j]]++;
        if(um[s[j]]==1){
            //means ek naya distinct character mila
            count++;
        }
        //conditions
        if(count==k){
            res=max(res,j-i+1);
        }
        
        //overshooting count
        
        
        j++;
        
    }
    return res;
    }
};