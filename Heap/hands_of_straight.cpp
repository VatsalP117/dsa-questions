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

//optimal (still does not use heaps tho lol but some solutions do apparaently)
Main idea: if the min element rn is 1, vo to group start karega hi aur usko 2 and 3 chaiye hi (if gSize==3)
so we try to start a group from minimum elements (Map mai apne aap sorted hi and we store num of occurences as well)
    bool isNStraightHand(vector<int>& arr, int groupSize) {
        int n=arr.size();
        if(n%groupSize!=0) return false;
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        int numGroups=n/groupSize;
        for(int i=0;i<numGroups;i++){
            auto it=m.begin();
            it->second--;
            int val=it->first;
            cout<<i<<" "<<val<<endl;
            if(it->second==0){
                m.erase(val);
            }
            for(int j=1;j<groupSize;j++){
                if(m.find(val+j)!=m.end() && m[val+j]>0){
                    m[val+j]--;
                    if(m[val+j]==0){
                        m.erase(val+j);
                    }
                }
                else{
                    return false;
                }
            }

        }
        return true;
    }


//same code and logic bas optimized a bit more (from lc solutions)
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        //base case 
        int n=hand.size();

        if(hand.size()%groupSize!=0){
            return false;
        }

        //for reamining we will check whether we can make a group where next index is current index+1
        
        //can be done using ordered map
        map<int,int>mapping;
        for(auto &card : hand){
            mapping[card]++;
        }

        //now check if value is present or not
        while(!mapping.empty()){
            int curr=mapping.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mapping[curr+i]==0){ //mean not present 
                    return false; 
                }
                else if(--mapping[curr+i]<1){
                    // mean after this iteration count of that value will be less than 1
                    mapping.erase(curr+i);
                }
            }
        }

        return true;        
    }