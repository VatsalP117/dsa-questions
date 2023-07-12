//expected logarithmic complexity

//my code(kinda brute)
void num_two_five(int val,vector<int> &v){
     while(val>0 && val%2==0){
        v[0]++;
        val=val/2;
    }
    while(val>0 && val%5==0){
        v[1]++;
        val=val/5;
    }
}
int Solution::trailingZeroes(int A) {
    vector<int> v(2,0);
    for(int i=1;i<=A;i++){
        num_two_five(i,v);
    }
    int numZero=min(v[0],v[1]);
    return numZero;
}


//optimal
//2 ko lite lo bhot hote hai bas 5 kitne hia pata karo
//ab 25! hai to 5,10,15,20,25 sab ek ek 5 denge. 25 to 2 baar 5 dega to /5 se ek 5 le liya ext iteration mai dusra
 int trailingZeroes(int n) {
        int ans = 0;
        while (n>0){
            ans += n/5;
            n = n/5;
        }
        return ans;
    }