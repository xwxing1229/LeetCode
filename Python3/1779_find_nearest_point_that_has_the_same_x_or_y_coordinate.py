# https://leetcode.cn/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/

class Solution:
    def nearestValidPoint(self, x, y, points):
        """
        Inputs:
            x: int
            y: int
            points: list[list[int]]
        Outputs:
            res: int
        """
        res, dist = -1, -1
        for i, p in enumerate(points):
            if p[0] == x or p[1] == y:
                d = abs(p[0] - x) + abs(p[1] - y)
                if dist < 0 or d < dist:
                    res = i
                    dist = d
        return res