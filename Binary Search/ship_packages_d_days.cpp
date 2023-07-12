//my code
bool chalega_kya(vector<int>&weights,int posans,int days)
    {
        int n=weights.size();
        int count=0,posday=1; //count says weight accumulated on a curr_day till now
        for(int i=0;i<n;i++)
        {
            if(weights[i]>posans)
            return false;
            if(count+weights[i]>posans)
            {
                count=0;
                posday++;
            }
            count+=weights[i];

        }
        if(posday<=days)
        return true;
        else
        return false;

    }
int leastWeightCapacity(vector<int> &weights, int d)
{
    // Write your code here.
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0),ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(chalega_kya(weights,mid,d)==false){
                //need more capacity
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
    return ans;
}