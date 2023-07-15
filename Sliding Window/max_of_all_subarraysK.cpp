//not optimal
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    vector<int> ans;
    int n=A.size();
    multiset<int,greater<int>> s;
  
    int i=0;
    int j=0;
    while(j<n){
        //calculations
        s.insert(A[j]);
        
        //if not reached size
        if(j-i+1<B){
            j++;
        }
        
        else if(j-i+1==B){
            //ans
            ans.push_back(*s.begin());
            
            //slide
            if(s.find(A[i]) != s.end())

            {

                s.erase(s.find(A[i]));

            }
            i++;
            j++;
            
        }
        
    }
    return ans;
}


//optimal
vector<int> Solution::slidingMaximum(const vector<int> &arr, int k) {
   deque<int>q;
   //q ke front mai max element
   //agar ek add kar rahe ho to uske pehle jo usse chote the vo kisi kaam kenhai kyuki aage ksi window mai aayenge nahi vo
   //so remove them
   //but koi chota element aa raha h to baadm eto usko rakhenge
   //kyuki bade element pop ho jaye fir vo bachega to kaam aa sakta h
   int n=arr.size();
        int i=0,j=0;
        vector<int>res;
        while(j<n){
            while(!q.empty() && q.back()<arr[j]) q.pop_back();
            q.push_back(arr[j]);
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                res.push_back(q.front());
                if(q.front()==arr[i]) q.pop_front();
                i++;
                j++;
            }
        }
        return res;
}