# https://leetcode.cn/problems/maximum-consecutive-floors-without-special-floors/

class Solution:
    def maxConsecutive(self, bottom, top, special):
        """
        Inputs:
            bottom, top: int
            special: list[int]
        Outputs:
            res: int
        """
        special.sort()
        res = max(special[0] - bottom, top - special[-1])
        for i in range(1, len(special)):
            res = max(res, special[i] - special[i-1] - 1)
        return res