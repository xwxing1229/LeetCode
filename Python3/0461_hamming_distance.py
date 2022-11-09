# https://leetcode.cn/problems/repeated-substring-pattern/

class Solution:
    def hammingDistance(self, x, y):
        """
        Inputs:
            x: int
            y: int
        Outputs:
            res: int
        """

        z = x ^ y
        res = 0
        while z > 0:
            res += (z & 1)
            z = z >> 1
        return res