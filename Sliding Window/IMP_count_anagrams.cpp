//problem linK:https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

	int search(string pat, string txt) {
	    // code here
	    int n=txt.size();
	    int k=pat.size();
	    unordered_map<char,int> um;
	    for(char it:pat){
	        um[it]++;
	    }
	    //eg if pat="aaba" we are storing a:3, b:1 in map
	    int count=um.size(); //basically number of distinct characters in pattern
	    int i=0;
	    int j=0;
	    int ans=0;
	    
	    while(j<n){
	        //calculations
	        if(um.find(txt[j])!=um.end()){
	            um[txt[j]]--;
	            //eg a:3 this means 3 maise ek a to mil gya to aur 2 dhundhne hai so a:2
	            if(um[txt[j]]==0){
	                count--;
	                //ek character ke saare occurences mil gaye to usko elimated
	            }
	        }
	        
	        //if not size=k
	        if(j-i+1<k){
	            j++;
	        }
	        
	        //size reached
	        else if(j-i+1==k){
	            //calculate ans
	            if(count==0){
	                ans++;
	            }
	            //slide
	            if(um.find(txt[i])!=um.end()){
	                um[txt[i]]++;
	                if(um[txt[i]]==1){
	                    count++;
	                }
	            }
	            i++;
	            j++;
	            
	        }
	    }
	    return ans;
	}