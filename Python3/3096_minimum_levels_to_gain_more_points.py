# https://leetcode.cn/problems/minimum-levels-to-gain-more-points/

class Solution:
    def minimumLevels(self, possible):
        """
        Inputs:
            possible: list[int]
        Outputs:
            res: int
        """
        n = len(possible)
        cumsum = [0 for _ in range(n+1)]
        for i, p in enumerate(possible):
            cumsum[i+1] = cumsum[i] + 2 * p - 1
        total = cumsum[-1]
        for i in range(1, n):
            if cumsum[i] > total - cumsum[i]:
                return i
        return -1