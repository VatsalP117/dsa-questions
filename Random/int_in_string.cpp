vector<int> Solution::solve(string A) {
    vector<int> ans;
    int n=A.size();
    if(n==0) return ans;
    int j=0;
    string temp="";
    while(i<n && j<n){
        if(A[j]!=','){
            temp+=A[j];
            j++;
            
        }
        else{
            //we found the number to add
            int num=stoi(temp);
            ans.push_back(num);
            temp="";
            j++;
        }
    }
    //add the last number khudse
    ans.push_back(stoi(temp));
    return ans;
    
}
//without library function
vector<int> Solution::solve(string A) {
    int n = A.size();
    assert(1 <= n && n <= 1e5);
    for(char &x: A) assert(x == ',' || isdigit(x));
    vector<int> ans;
    int num = 0;
    for(char &x: A){
        if(x == ','){
            ans.push_back(num);
            num = 0;
        }
        else{
            num = num*10 + x-'0';
        }
    }
    ans.push_back(num);
    return ans;
}