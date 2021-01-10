# https://leetcode-cn.com/problems/add-strings/

class Solution:
	def addStrings(self, num1:str, num2:str) -> str:
		len1 = len(num1)
		len2 = len(num2)
		# Add 0s such that num1 and num2 have same length.
		if len1 < len2:
			num1 = '0' * (len2-len1) + num1
		else:
			num2 = '0' * (len1-len2) + num2

		carry = 0
		res = ''
		for i in range(len(num1)-1,-1,-1):
			res = str((int(num1[i])+int(num2[i])+carry) % 10) + res
			carry = (int(num1[i])+int(num2[i])+carry) // 10
		if carry == 1:
			res = '1' + res
		return res