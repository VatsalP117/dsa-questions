//leetcode 4

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //idea is to use symmetry
        //say arr1= 1 4 6 11
        //arr2 = 2 8 10 14
        //so total elements =8 , property of median is sorted mai dono side same number of elements
        //so left mai 4 and right mai chaar
        //= [1 4 6], 2 | 11, [8,10,14]
        //| means median = (max(l1,l2)+min(r1,r2))/2
        //this was for even elements, odd honge total to ek hi hoga median
        //take 1 extra on left and the max(l1,l2) will be median
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int totalElements=n1+n2;
        if(n1==0){
            if(n2%2==0){
                return (double)(nums2[n2/2]+nums2[n2/2-1])/2.0;
            }
            else return (double)nums2[n2/2];
        }
        int left=(n1+n2+1)/2;//covers both even-odd cases and tells num elements required on left
        int low=0; //means take 0 elements from nums1
        int high=n1;//means take all n elements from num2
        while(low<=high){
            int mid=(low+high)/2;
            //initliaze l1,l2,r1,r2 for cases where they dont exits (eg when you take zero elements from nums1)
            int l1=INT_MIN;
            int l2=INT_MIN;
            int r1=INT_MAX;
            int r2=INT_MAX;
            //means take all elements from nums1[0]..nums1[mid-1]
            int mid2=left-mid;//itne element nums2 se uthane hai
            if(mid-1>=0){
                l1=nums1[mid-1];
            }
            if(mid2-1>=0){
                l2=nums2[mid2-1];
            }
            if(mid<n1){
                r1=nums1[mid];
            }
            if(mid2<n2){
                r2=nums2[mid2];
            }
            //check if valid
            if(l1<=r2 && l2<=r1){
                //mil gya lessgooo
                cout<<mid<<" "<<mid2<<endl;
                
                if(totalElements%2==1){
                    return max(l1,l2);
                }
                else{
                    cout<<mid<<" "<<mid2<<endl;
                    cout<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<" "<<endl;
                    // cout<<nums1[mid]<<endl;
                    return (double)((double)max(l1,l2)+min(r1,r2))/2.0;
                }
            }
            else if(l1>r2){
                //means 
                high=mid-1;
            }
            else low=mid+1;
        }
        return -1;
    }
};