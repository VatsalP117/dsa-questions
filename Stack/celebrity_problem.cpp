//link:https://www.codingninjas.com/studio/problems/the-celebrity-problem_982769?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=2
 Instead of checking each and every member of the party , we will use the elimination technique
 Push all to stack and start popping two at a time (i and j) is i knows j , i is not a celebrity so just push j back
 and vice versa. last mai you will have a potential ans not the definite ans so just check all cases for that candidate

 #include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	stack<int> st;
	for(int i=0;i<n;i++)st.push(i);
	while(st.size()>1){
		int i=st.top();
		st.pop();
		int j=st.top();
		st.pop();
		if(knows(i,j) && i!=j){
			//fir i to pakka celebrity nahi hai bas j ko vapaa daal do
			st.push(j);
		}
		else if(knows(i,j)==false && i!=j){
			st.push(i);
		}
	}
	if(st.empty()) return -1;
	int candidate=st.top();
	for(int i=0;i<n;i++){
		if(i!=candidate){
			if(knows(i,candidate)==false || knows(candidate,i)==true){
				return -1;
			}
		}
	}
	return candidate;
}