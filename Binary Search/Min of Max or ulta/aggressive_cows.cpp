//watch strivers video to get a idea of this kinda pattern


//start from1 and see can we try to maintain a distance of atleast 1?
//if we can lets try 2? done? try 3 then 4
//greedily place 1st cow on1st place then try to pick next position if it satisfies the min distance we are trying to maintain
//max possible distance (say only 2 cows)=arr[n-1]-arr[0](max-min)

bool chalega_kya(vector<int> &arr,int num_cows,int dist){
    int curr_cows=1;
    int last=arr[0]; //last kaha pe place kiya
    for(int i=1;i<arr.size();i++){
        if(arr[i]-last>=dist){
            //can place here
            curr_cows++;
            last=arr[i];
        }
    }
    if(curr_cows>=num_cows)return true;
    else return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int n=stalls.size();
    
    int low=1;
    int high=stalls[n-1]-stalls[0];
    int ans=high;
    while(low<=high){
        int mid=(low+high)/2;
        if(chalega_kya(stalls,k,mid)==false){
            //itna distance to possible nahi bhai chota farm hai
            //try smaller one
            high=mid-1;
        }
        else{
            //itna distance to eazy but can we maintain even more than this???
            ans=mid;
            low=mid+1;
        }
    }
    return ans;
}