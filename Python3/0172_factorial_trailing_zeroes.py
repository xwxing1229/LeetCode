# https://leetcode-cn.com/problems/factorial-trailing-zeroes/

class Solution:
    def trailingZeroes(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """
        
        res = 0
        while n > 0:
            n = n // 5
            res = res + n
        return res