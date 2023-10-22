# https://leetcode.cn/problems/reducing-dishes/

class Solution:
    def maxSatisfaction(self, satisfaction):
        """
        Inputs:
            satisfaction: list[int]
        Outputs:
            res: int
        """
        satisfaction.sort()
        res, n = 0, len(satisfaction)
        cumsum = [0 for _ in range(n+1)]
        for i, s in enumerate(satisfaction):
            cumsum[i+1] = cumsum[i] + s
            res += (i+1) * s
        tmp = res
        for i in range(n):
            tmp -= cumsum[-1] - cumsum[i]
            res = max(res, tmp)
        return res