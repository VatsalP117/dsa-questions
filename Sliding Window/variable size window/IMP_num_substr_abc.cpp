//bhai mujhe khud nahi pata iska ans maine kaise nikala ekdum acche se to
//link:https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/submissions/
//whats the logic behind res+=(n-j)
//say for string abcdef. you got the window abc (i=0, j=2) jaha count=0
//now you can extend this window aage since ek baar abc chaiye tha vo mil gya: abcd,abcde,abcdef
//basically end(j) ke baad jitne chars hai sabko add karke aur substr ban jayegi so n-j substrings
int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int> occ(3,1);
        int count=3;
        int i=0;
        int j=0;
        int res=0;
        while(j<n){
            int ind=s[j]-'a';
            if(ind>=0 && ind<=2){
                //means one of a,b,c
                occ[ind]--;
                if(occ[ind]==0) count--;
            }
            if(count==0){
                
                while(count==0){
                    res+=(n-j);
                    int new_ind=s[i]-'a';
                    if(new_ind>=0 && new_ind<=2){
                        occ[new_ind]++;
                        if(occ[new_ind]==1)count++;
                        i++;
                    }
                    
                }
            }
            j++;
        }
        return res;
    }