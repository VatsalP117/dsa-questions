//link: https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/description/
//best explaination ever for this: https://www.youtube.com/watch?v=jdSRCHUFUDc&t=610s

// Idea:
// instead of iterating over all substrings anc checking number of distinct characters since vo O(n2 ho jayega), lets do this:
// we know that characters are limited i.e 26 only.
// for a character say ='c', just find out its present in how many substrings (i.e uska contribution)
// similar find contribution (number of substrings in which its present) and add them up to find our ans 

// now how do we do that?
// first of all, how many total substrings/subarrays are there of an array/string of size n?
// say [1,2,3,4] => |1|2|3|4| youu can choose any two of these 5 bars and unke bich ka ek subarray hoga
// so number of subarray/substring=(n+1 C 2)=(N*(N+1))/2
// so ye to ho gaye total 

// now you iterate over the aray, any such chunk you find usme vo character jiska contribution nikal rahe h nahi ho 
// say you have a chuk of size 3 jisme no 'a' is present, all substrings of that chunk (3*4/2) will be removed fom total substrings
// aise hi find all such chunks and remove 
class Solution {

public:
    long long contribution(char ch,string &s){
        long long n=s.size();
        long long tot_subarr=((n+1)*n)/2;
        //now find number of subarrays jisme vo ch nahi hai
        long long curr_size=0;
        long long res=0;
        for(int i=0;i<n;i++){
            if(s[i]==ch){
                res+=((curr_size+1)*curr_size)/2;
                curr_size=0;
            }
            else{
                curr_size++;
            }
        }
        res+=((curr_size+1)*curr_size)/2;
        return tot_subarr-res;

    }
    int uniqueLetterString(string s) {
        long long res=0;
        
        for(int i=0;i<26;i++){
            char ch='A'+i;
            //ab iska character ka contribution nikalke add to res
            res+=contribution(ch,s);
        }
        return res;
    }
};