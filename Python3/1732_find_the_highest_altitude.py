# https://leetcode.cn/problems/find-the-highest-altitude/

class Solution:
    def largestAltitude(self, gain):
        """
        Inputs:
            gain: list[int]
        Outputs:
            res: int
        """
        res, cur = 0, 0
        for g in gain:
            cur += g
            if res < cur:
                res = cur
        return res