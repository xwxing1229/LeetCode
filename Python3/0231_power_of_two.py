# https://leetcode.cn/problems/power-of-two/

class Solution:
    def isPowerOfTwo(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: bool
        """
        if (n > 0) and (n & (n-1)) == 0:
            return True
        else:
            return False