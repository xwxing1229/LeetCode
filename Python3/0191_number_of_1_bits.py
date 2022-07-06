# https://leetcode.cn/problems/number-of-1-bits/
        
class Solution:
    def hammingWeight(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """

        res = 0
        for i in range(32):
            res = (n & 1) + res;
            n = n >> 1
        return res