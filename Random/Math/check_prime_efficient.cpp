// Brute force:
//  i=2 se leke n-1 tak loop chala do koi bhi divide kar diya to false varna true
//  T.C= O(n) 

// Better approach: O(n^1/2) i.e square root of n time complexity
// idea: divisors always occur in pairs 
// eg: 30: (1,30),(2,15),(3,10),(5,6)
//         elements of pair multiply to n 
//         so if(x,y) is a pair s.t x*y=n, and x<=y (i.e just considering x as the smaller divisor)
//         then x*x<=n
//         so x<square_root(n)
        // to bas 2 se n^1/2 tk hi check karna padega

    int isPrime(int N){
        if(N==1) return false;
        for(int i=2;i*i<=N;i++){
            if(N%i==0) return 0;
        }
        return 1;
    }

// Efficient
// To save on a lot of iterations, pehle hi check for N%2 and N%3==0 wala case 
// now when you terate, you dont have to check for even possible divisors (2,4,6,8,10.. and so on) since agar 2 se divisible nahi to ye sabse bhi nahi hoga 
// similar,3 ke multiples ke liye bhi check nahi karna (3,6,9...) for same reasons
// therefore, kiske liye check karna hai? jo 2 aur 3 dono se divisible na ho => 5,7,11,13,17..

int isPrime(int n){
        // code here
        if(n==1) return 0;
        if(n==2 || n==3) return 1;
        if(n%2==0 || n%3==0) return 0;
        for(int i=5;i*i<=n;i=i+6){
            if(n%i==0 || n%(i+2)==0){
                return 0;
            }
        }
        return 1;
    }


