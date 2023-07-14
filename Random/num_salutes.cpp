//https://www.interviewbit.com/problems/salutes/
// In a long hallway some soldiers are walking from left to right and some from right to left all at the same speed.

// Every time while walking they cross through another soldier they salute and move ahead.

// Given a string A of length N showing the soldiers' direction they are walking. 
// '<' denotes a soldier is walking from right to left, and '>' denotes a soldier is walking from left to right. 
// Return the number of Salutes done.


//i wrote this solution completly by myself and its exactly same as OFFICIAL SOLUTION!!
long Solution::countSalutes(string A) {
    int n=A.size();
    long long res=0;
    long long num=0;
    for(int i=n-1;i>=0;i--){
        if(A[i]=='<'){
            num++;
        }
        else{
            res+=num;
        }
    }
    return res;
}