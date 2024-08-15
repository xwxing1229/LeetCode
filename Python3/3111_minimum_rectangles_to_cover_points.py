# https://leetcode.cn/problems/minimum-rectangles-to-cover-points/

class Solution:
    def minRectanglesToCoverPoints(self, points, w):
        """
        Inputs:
            points: list[list[int]]
            w: int
        Outputs:
            res: int
        """
        points.sort()
        res = 1
        end = points[0][0] + w
        for x, y in points:
            if x > end:
                res += 1
                end = x + w
        return res