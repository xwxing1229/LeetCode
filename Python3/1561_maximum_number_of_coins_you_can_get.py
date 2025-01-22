# https://leetcode.cn/problems/maximum-number-of-coins-you-can-get/

class Solution:
    def maxCoins(self, piles):
        """
        Inputs:
            piles: list[int]
        Outputs:
            res: int
        """
        res = 0
        piles.sort()
        n = len(piles)
        for i in range(n-2, n//3-1, -2):
            res += piles[i]
        return res