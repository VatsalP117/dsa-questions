//method 1
bool isKthBitSet(int n, int k)
{
    // Write your code here.
    //1 left hsitfed by k-1 bits is a number isme sirf kth bit set hai baaki sab 0 hai
    //so uska n se and pe op non zero aayga if and only if kth bit in n is set as well
        if((n & (1<<(k-1)))!=0) return true;
        else return false;
}

//method 2 (move the kth bit to last position and fir and with 1)
bool isKthBitSet(int n, int k)
{
    // Write your code here.
        if((n>>(k-1)) & 1!=0) return true;
        else return false;
}