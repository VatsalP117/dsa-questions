//https://www.codingninjas.com/studio/problems/kth-missing-element_893215?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
//

//brute force O(N) (cannot understand intuition)
int missingK(vector < int > vec, int n, int k) {
    // Write your code here.
    for(int i=0;i<n;i++){
        if(vec[i]<=k){
            k++;
        }
        else{
            break;
        }
    }
    return k;
}