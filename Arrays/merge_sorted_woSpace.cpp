//to merge in non decreasing order in nums1 itself usme extra space di hai with 0 in it
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;//at the last actual element of nums1
        int j=n-1; //at the last element of nums2
        int ptr=(n+m-1); //at the last place of nums1
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[ptr]=nums1[i];
                i--;
                ptr--;
            }
            else{
                nums1[ptr]=nums2[j];
                j--;
                ptr--;
            }
        }
        while(i>=0){
            nums1[ptr]=nums1[i];
            i--;
            ptr--;
        }
        while(j>=0){
            nums1[ptr]=nums2[j];
            j--;
            ptr--;
        }
    }