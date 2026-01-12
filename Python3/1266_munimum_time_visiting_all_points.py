# https://leetcode.cn/problems/minimum-time-visiting-all-points/

class Solution:
    def minTimeToVisitAllPoints(self, points: list[list[int]]) -> int:
        res = 0
        for i in range(1, len(points)):
            prev, curr = points[i-1], points[i]
            res += max(abs(curr[0] - prev[0]), abs(curr[1] - prev[1]))
        return res