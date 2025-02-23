# https://leetcode.cn/problems/number-of-even-and-odd-bits/

class Solution:
    def evenOddBit(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: list[int]
        """
        res = [0, 0]
        idx = 0
        while n:
            res[idx] += (n & 1)
            n >>= 1
            idx = 1 - idx
        return res