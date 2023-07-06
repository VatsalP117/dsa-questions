//approach 1 (mine)
int findContentChildren(vector<int>& g, vector<int>& s) {
       int n=g.size();
       int m=s.size();
       int i=0;
       int j=0;
       sort(s.begin(),s.end());
       sort(g.begin(),g.end());
       while(i<n && j<m){
           if(s[j]>=g[i]){
               //child content, move ahead to next child
               j++;
               i++;

           }
           else{
               j++;
               //try with bigger cookie
           }
       }
       return i;
    }

//approach 2 from yt
int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=g.size()-1;//1st pointer points to the greediest child
        int j=s.size()-1;//2nd pointer points to the largest cookie
        int numChild=0;
        while(i>=0 && j>=0){
            if(s[j]>=g[i]){
                numChild++;
                i--;
                j--;
            }
            else{
                //we already have tried the largest cookie available. so move on to the lesser greedy child
                i--;
            }
        }
        return numChild;
    }