eg: arr[]=[1,6,8,2,7,16]
we are asked to find sum of all values between any 2 given indices say 2 and 5
worst case T.C= O(n). This is not good enough for us, we want O(logn)
Answer to this is segment tree

Segment => perform a query on a range (query can be sum,min,max,product etc in a range) in logn time complexity
Update function is also takes logn time (ab arr ka data badla to segment tree ka data bhi badalne padega na)

Segment tree is a binary tree which has info about the interval and the operation performed (eg: bw 2 and 5 index and sum => gives sum between 2 and 5 index)
