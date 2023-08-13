void cycleSort(vector<int> &arr){
    int n=arr.size();
    int i=0;
    while(i<n){
        //only move i ahead if this is at correct position
        int correctIndex=arr[i]-1;
        if(correctIndex==i){
            i++;
        }
        else{
            swap(arr[i],arr[correctIndex]);
        }
    }
