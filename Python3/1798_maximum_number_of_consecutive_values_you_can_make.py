# https://leetcode.cn/problems/maximum-number-of-consecutive-values-you-can-make/

class Solution:
    def getMaximumConsecutive(self, coins):
        """
        Inputs:
            coins: list[int]
        Outputs:
            res: int
        """
        coins.sort()
        res = 1
        for coin in coins:
            if coin > res:
                break
            res += coin
        return res