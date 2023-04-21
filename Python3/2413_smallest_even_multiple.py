# https://leetcode.cn/problems/smallest-even-multiple/

class Solution:
    def smallestEvenMultiple(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """
        if n % 2 == 0:
            return n
        else:
            return n + n