
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        //insert all those strictly before new interval
        //which? jinka end < naye ka start

        int i=0;
        int n=intervals.size();
        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }

        //those who overlap unko merge pls
        //since yaha means last interval ka end > apna start (like prev ends at 7 and new starts from 4)
        //so prev ka start must end before new end varna overlap kaha hoga
        //collect all overallping and push at once
        int right=newInterval[1];
        int left=newInterval[0];
        while(i<n && intervals[i][0]<=right){
             left=min(intervals[i][0],left);
             right=max(intervals[i][1],right);
             
             i++;
        }
        ans.push_back({left,right});

        //insert strictly greater (all remaining )
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }