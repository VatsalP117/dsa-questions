//N meetings in one room
//sort by end times
static bool cmp(pair<int,int> a,pair<int,int> b){
        return a.second<b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> v; //to store start and end times
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),cmp);
        int count=1; //coz pehli meeting to hogi hi
        int ansStart=v[0].first;
        int ansEnd=v[0].second;
        for(int i=1;i<n;i++){
            if(v[i].first>ansEnd){
                count++;
                ansEnd=v[i].second;
            }
        }
        return count;
    }

//modificaton: return 1st meetinsg will be done like 1st,3rd and 4th meeting aise
    static bool cmp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
        return a.second.second<b.second.second;
    }
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<pair<int,pair<int,int>>> v; //{i,{start,end}}
        for(int i=0;i<N;i++){
            v.push_back({i+1,{S[i],F[i]}});
        }
        sort(v.begin(),v.end(),cmp);
        //sorted
        vector<int> ans;//to store which meetings are done
        int ansEnd=v[0].second.second;
        ans.push_back(v[0].first);
        for(int i=1;i<N;i++){
            if(v[i].second.first>ansEnd){
                ansEnd=v[i].second.second;
                ans.push_back(v[i].first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }