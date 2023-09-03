# https://leetcode.cn/problems/eliminate-maximum-number-of-monsters/

class Solution:
    def eliminateMaximum(self, dist, speed):
        """
        Inputs:
            dist, speed: list[int]
        Outputs:
            res: int
        """
        n = len(dist)
        t = [(dist[i] + speed[i] - 1) // speed[i] for i in range(n)]
        t.sort()
        res = 0
        for i in range(n):
            if t[i] - i > 0:
                res += 1
            else:
                break
        return res