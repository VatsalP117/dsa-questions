#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	
	public:
		stack<int> s;
		stack<int> supportStack;
		// Constructor
		minStack() 
		{ 
			// Write your code here.
			
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			s.push(num);
			if(supportStack.empty() || supportStack.top()>=num){
				supportStack.push(num);
			}
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(supportStack.empty()==false && supportStack.top()==s.top()){
				
				supportStack.pop();
			}
			int ans=-1;
			if(s.empty()==false){
				ans=s.top();
				s.pop();
			}
			return ans;
			
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(s.empty()) return -1;
			else return s.top();

		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(supportStack.empty()) return -1;
			else return supportStack.top();
		}
};