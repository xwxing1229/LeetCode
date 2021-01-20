# https://leetcode-cn.com/problems/add-to-array-form-of-integer/

class Solution:
	def addToArrayForm(self, A:List[int], K:int) -> List[int]:
		a = ''
		for i in range(len(A)):
			a = a + str(A[i])
		add = str(int(a) + K)
		
		res = []
		for i in add:
			res.append(int(i))
		return res
