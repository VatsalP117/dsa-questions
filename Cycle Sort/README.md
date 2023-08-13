When given numbers range from 1 to N, use cyclic sort (N is the size of array)

eg: arr=[3,5,2,1,4] N=5
after sorrting: arr=[1,2,3,4,5] i.e the correct index for any value = value -1
but how will we sort using this fact?

'3',5,2,1,4 => is 3 at correct index (i.e 2)? No, then swap it
'2',5,3,1,4 => is 2 at correct index (i.e 1)? No, then swap it
'5',2,3,1,4 => swap 5
'4',2,3,1,5 => swap 4
1,2,3,4,5 => sorted
In worst case: N-1 swaps will be needed to give everyone their correct position. How? If N-1 elements are at their correct position, manje last wala bhi correct position pe hi hoga na dost
so N-1 swaps + N comparisions (har element pe check to karna padega na sahi ya galat) => T.C is O(n)
