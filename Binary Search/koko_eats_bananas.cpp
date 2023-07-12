int find_max(vector<int> &v){
    int res=-1;
    for(int i=0;i<v.size();i++){
        if(v[i]>res){
            res=v[i];
        }
    }
    return res;
}
int required_time(vector<int> v,int rate){
    int res=0;
    for(int i=0;i<v.size();i++){
        if(v[i]%rate==0){
            res+=v[i]/rate;
        }
        else{
            res+=v[i]/rate +1;
        }
    }
    return res;
}
int minimumRateToEatBananas(vector<int> v, int h) {
    // Write Your Code Here
    //max speed will be the max number of bananas in a pile coz usse zyada khaana is waste
    int n=v.size();
    
    int low=1;
    int high=find_max(v);
    int ans=find_max(v);
    while(low<=high){
        int mid=(low+high)/2;
        if(required_time(v,mid)>h){
            //wont work so increase the rate of eating Koko
            low=mid+1;
        }
        else{
            //this works so lets tsore it look if a smaller rate can work or not
            ans=mid;
            //check for a lower value
            high=mid-1;
        }
    }
    return ans;
}