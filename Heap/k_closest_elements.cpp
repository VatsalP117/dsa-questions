//k largest elements tha vaisa hi hai
//ab number ke badle difference dalenge heap mai
//closest mtlb min difference wali chaiye to min values niche chaiye kyuki par se to pop karenge
//so use max heap
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq; //max heap
    vector<int> ans;
    for(int i=0;i<arr.size();i++){
        int diff=arr[i]-x; 
        pq.push({abs(diff),arr[i]});
        if(pq.size()>k) pq.pop();
    }
    //ab heap mai k sabse smallest difference wale elements hai bas
    for(int i=0;i<k;i++){
        auto it=pq.top();
        pq.pop();
       ans.push_back(it.second);
    }
    sort(ans.begin(),ans.end());
    return ans;
    }