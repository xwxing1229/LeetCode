# https://leetcode.cn/problems/reverse-bits/
        
class Solution:
    def reverseBits(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """

        res = 0
        for i in range(32):
            res = (res << 1) | (n & 1)
            n = n >> 1
        return res