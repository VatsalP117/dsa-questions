#include <bits/stdc++.h> 
int lcs(string &s, string &t){
	//	Write your code here.
	int n=s.size();
	int m=t.size();
	//direct tabulation needed
	//consecutive so depends on i-1,j-1 only
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	int res=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==t[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
				res=max(res,dp[i][j]);

			}
			else{
				dp[i][j]=0; //no need since already zero but just to show
			}
		}
	}
	return res;

}