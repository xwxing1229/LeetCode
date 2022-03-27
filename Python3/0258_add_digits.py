# https://leetcode-cn.com/problems/add-digits/

class Solution:
	def addDigits(self, num:int) -> int:
		while True:
			res = 0
			for i in str(num):
				res = res + int(i)
			if res > 9:
				num = res
			else:
				break
		return res
