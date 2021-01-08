# https://leetcode-cn.com/problems/add-binary/

class Solution:
	def addBinary(self, a:str, b:str) -> str:
		len_a = len(a)
		len_b = len(b)
		# Add 0s such that a and b have same length.
		if len_a < len_b:
			a = '0' * (len_b-len_a) + a
		else:
			b = '0' * (len_a-len_b) + b

		res = ''
		carry = 0
		for i in range(len(a)-1, -1, -1):
			res = str(int(a[i]) ^ int(b[i]) ^ carry) + res
			carry = (int(a[i]) + int(b[i]) + carry) > 1
		if carry == 1:
			res = '1' + res
		return res