int n=nums.size();
        int low=0;
        int mid=0;
        int high=n-1;
        //0..low-1 is the 0 wala section
        //low..mid-1 is the 1 wala section
        //mid..high is the unsorted section
        //high+1..n-1 is the 2 wala section

        while(mid<=high){
            //i.e while there is some unsorted section
            if(nums[mid]==0){
                //swap to the 0 wala section
                swap(nums[low],nums[mid]);
                low++; //since 0 section length increases
                mid++; //difference between low high same coz number of 1's kam thodi ho jayenge isse
            }
            else if(nums[mid]==1){
                    mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
                
            }
        }