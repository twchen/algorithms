''' Input: an array A of numeric values
    Output: an array P where P[i] contains the index of the previous larger element to A[i], or -1 if no such element exists.
    Time complexity: O(n)
'''

def previousLarger(A):
	if len(A) == 0:
		return []
	P = [-1] * len(A) # initialize the return array
	stack = [] # stack stores the indexes of previous elements that are >= A[i-1]
	for i in range(0, len(A)):
		while stack and A[stack[-1]] <= A[i]:
			stack.pop()
		if stack:
			P[i] = stack[-1]
		stack.append(i);
	return P;		
