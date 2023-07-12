#include <bits/stdc++.h> 
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    int low=0;
    int high=n-1;
    int first=-1;
    int last=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>k){
            //move to the left
            high=mid-1;
        }
        else if(arr[mid]<k){
            //move to right
            low=mid+1;
        }
        else{
            //equal
            first=mid;
            //but check if there exists aother occurence on the left as well
            high=mid-1;
        }
    }
    low=0;
    high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>k){
            //move to the left
            high=mid-1;
        }
        else if(arr[mid]<k){
            //move to right
            low=mid+1;
        }
        else{
            //equal
            last=mid;
            //but check if someone on the right is equal to k as well
            low=mid+1;
        }

    }
    return {first,last};
}