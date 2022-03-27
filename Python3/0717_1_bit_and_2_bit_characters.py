# https://leetcode-cn.com/problems/1-bit-and-2-bit-characters/

class Solution:
	def isOneBitCharacter(self, bits:List[int]) -> bool:
		res = bits.pop()
		# If the following way is used, an error will occur
		# because bits cannot be empty.
		# while bits.pop():
		while bits and bits.pop():
			res = res ^ 1 # bitwise operation
		return 1 - res
