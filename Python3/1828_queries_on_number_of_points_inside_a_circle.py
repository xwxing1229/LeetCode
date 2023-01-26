# https://leetcode.cn/problems/queries-on-number-of-points-inside-a-circle/

class Solution:
    def countPoints(self, points, queries):
        """
        Inputs:
            points, queries: list[list[int]]
        Outputs:
            res: list[int]
        """
        res = [0 for _ in range(len(queries))]
        for i, q in enumerate(queries):
            x, y, r2 = queries[i][0], queries[i][1], queries[i][2] * queries[i][2]
            cnt = 0
            for px, py in points:
                if (px - x) * (px - x) + (py - y) * (py - y) <= r2:
                    cnt += 1
            res[i] = cnt
        return res