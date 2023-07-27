//thoda brute (normal binary search on every row)
int find_num_ones(vector<int> &arr){
    int size=arr.size();
    int low=0;
    int high=size-1;
    int ans=-1;//1st occurence of 1
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==1){
            ans=mid;
            high=mid-1;
        }
        else{
            //1 to right mai reh gya bhai yaha kya kar raha hai
            low=mid+1;
        }
    }
    if(ans==-1) return 0;
    else return size-ans;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    //    Write your code here.
    int maxi=0;
    int res=0;
    for(int i=0;i<n;i++){
        if(find_num_ones(matrix[i])>maxi){
            res=i;
            maxi=find_num_ones(matrix[i]);
        }
    }
    return res;
}

//optimal (based on row_col_sorted pattern)
//i could actually think of correlating a pattern seen before 1st time with this one!
//think of how aditya sir explained the flow of going from top right corner to traverse
//basically if you are at index j in a row and its one, all the indexes>j will be one as well since its sorted
//so number of ones= size of rows-j
//yahi concept se solved kiya hai
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    //    Write your code here.
    int maxi=0;
    int res=0;
    int curr_count=0;
    int i=0;
    int j=m-1;
    //initial at top right
    while(i<n && j>=0){
        if(matrix[i][j]==1){
            j--;
            curr_count=m-j;
            if(curr_count>maxi){
                maxi=curr_count;
                res=i;
            }
       }
        else{
            i++;//just go to niche wala row
        }
    }
    return res;
}
