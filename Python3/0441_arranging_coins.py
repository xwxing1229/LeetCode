# https://leetcode.cn/problems/arranging-coins/

class Solution:
    def arrangeCoins(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """

        res = int(sqrt(8*n + 1) - 1) // 2
        return res