//link: https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/
//Great video on helping to think and come to the solution: https://www.youtube.com/watch?v=c9FPc5GNROI

// Return the number of seconds needed to complete this process.

//Approach (using 2 observations)
//1. In the final result, all 1's will be on the left and all 0's on right. so for any 1, it will have to pass all the
//   zeros on its left once. Therefore, we can say that any 1 in the system will spend a second swapping with each 0 on its left
// so from 1. atleast (max number of 0 to the left of a 1) seconds to lagenge hi hai for sure

// 2. This bservation is abit difficult to grasp initially (do watch the linked video great explaination)
// (....1)1 for the last one to get included in the sorted system, the brackets ke andar wala system needs tobe sorted 
// only then the last one will be pprovided with the zeros to swap, so that willl take one more second after the bracket wala system is sorted 
// t=0:(0001)one
// t=1: 0010one
// t=2: 010one0
// t=3:10one00 (at this point you can see() wala system is sorted in itself if you ignore 'one')
// now you will need one more swap for the one for entire system to be sorted 
// t=4 1one000

    int secondsToRemoveOccurrences(string s) {
        int n=s.size();

        int num_zero=0;
        int seconds=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                num_zero++;
            }
            else if(s[i]=='1' && num_zero>0){
                //combining points 1 and 2
                seconds=max(seconds+1,num_zero);
            }
        }
        return seconds;
    }