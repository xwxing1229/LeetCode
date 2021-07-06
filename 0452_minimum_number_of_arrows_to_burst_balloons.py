# https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution:
    def findMinArrowShots(self, points):
        """
        Inputs:
            points: list[list[int]]
        Outputs:
            res: int
        """

        n = len(points)
        if n == 0:
            return 0

        points.sort()
        right = points[0][1]
        res = 1

        for i in range(1,n):
            if right >= points[i][0]:
                right = min(right, points[i][1])
            else:
                res = res + 1
                right = points[i][1]

        return res