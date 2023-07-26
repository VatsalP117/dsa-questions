//link:https://leetcode.com/problems/hand-of-straights/description/
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize,
and consists of groupSize consecutive cards.Given an integer array hand where hand[i] is the value written on the 
ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.


//brute without using heaps lmao
    bool isNStraightHand(vector<int>& arr, int groupSize) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        if(n%groupSize!=0) return false;
        int numGroups=n/groupSize;
        vector<int> groups(numGroups,-2);//-2 means group not yet started
        vector<int> sizes(numGroups,groupSize);
        for(int i=0;i<n;i++){
            int num=arr[i];
            bool flag=false;
            for(int j=0;j<numGroups;j++){
                if(num==groups[j]+1 && sizes[j]>0){
                    groups[j]=num;
                    sizes[j]--;
                    flag=true;
                    break;
                }
                else if(groups[j]==-2){
                    groups[j]=num;
                    sizes[j]--;
                    flag=true;
                    break;
                }
            }
            if(flag==false) return false;
        }
        return true;
    }
