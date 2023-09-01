# https://leetcode.cn/problems/number-of-ways-to-buy-pens-and-pencils/

class Solution:
    def waysToBuyPensPencils(self, total, cost1, cost2):
        """
        Inputs:
            total, cost1, cost2: int
        Outputs:
            res: int
        """
        res = 0
        for i in range(total, -1, -cost1):
            res += i // cost2 + 1
        return res