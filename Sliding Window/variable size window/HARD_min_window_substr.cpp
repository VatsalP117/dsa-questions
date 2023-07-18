    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        int res=INT_MAX;
        for(auto ch:t){
            mp[ch]++;
        }
        int start;//starting index of the string
        int n=s.length();
        int i=0,j=0,count=mp.size();
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                //means t mai jo character hai vo koi to aaya hai
                mp[s[j]]--;
                if(mp[s[j]]==0)
                //jitne occurences chaiye the saare mil gye is character ke
                    count--;
            }
            //if we have have hit the condition, store it and see if we can reduce length
            //how to reduce: remove chars not in t OR remove extra occurences of chars in t (unka map mai value <0 ho gya hoga)
            if(count==0){
                while(count==0){
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]==1) {
                            count++;
                            if(j-i+1<res){
                                res=j-i+1;
                                start=i;
                            }
                        }
                    }
                    i++;
                }  
            }
            j++;
        }
        if(res==INT_MAX) return "";
        string ans="";
        for(int ind=start;ind<start+res;ind++){
            ans+=s[ind];
        }
        return ans;
    }