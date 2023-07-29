//link: https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{
public:
    int solve(string &S,int i,int j,bool isTrue,vector<vector<vector<int>>> &dp){
        //base case
        if(i>j){
            //empty string
            return false; //basically 0 return kar dega c++
        }
        if(i==j){
            if(isTrue){
                return S[i]=='T';
            }
            else return S[i]=='F';
        }
        //base done
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        int mod=1003;
        int ans=0;
        for(int k=i+1;k<=j-1;k=k+2){
               int left_t=solve(S,i,k-1,true,dp);
               int right_t=solve(S,k+1,j,true,dp);
               int left_f=solve(S,i,k-1,false,dp);
               int right_f=solve(S,k+1,j,false,dp);
               
               if(S[k]=='&'){
                   if(isTrue){
                       ans+=(left_t*right_t)%mod;
                   }
                   else{
                       ans+= ((left_f*right_f)+(left_f*right_t)+(left_t*right_f))%mod;
                   }
               }
               else if(S[k]=='|'){
                    if(isTrue){
                       ans+=((left_t*right_t) + (left_t*right_f) + (left_f*right_t))%mod;
                   }
                   else{
                       ans+= (left_f*right_f)%mod;
                   }
               }
               else if(S[k]=='^'){
                    if(isTrue){
                       ans+=((left_t*right_f) + (left_f*right_t))%mod;
                   }
                   else{https://media.geeksforgeeks.org/img-practice/wheelfab-1680611378.svg
                       ans+= ((left_f*right_f)+(left_t*right_t))%mod;
                   }
                   
               }
        }
        return dp[i][j][isTrue]=ans%mod;
    }
    
    int countWays(int N, string S){
        // code here
        
        vector<vector<vector<int>>> dp(N,vector<vector<int>> (N,vector<int>(2,-1)));
        return solve(S,0,N-1,true,dp);
    }
};
