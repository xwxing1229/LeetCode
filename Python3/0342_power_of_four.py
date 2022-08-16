# https://leetcode.cn/problems/power-of-four/

class Solution:
    def isPowerOfFour(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: bool
        """
        if (n > 0) and ((n & (n-1)) == 0) and (n & 0b10101010101010101010101010101010 == 0):
            return True
        else:
            return False