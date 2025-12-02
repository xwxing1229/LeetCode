# https://leetcode.cn/problems/count-number-of-trapezoids-i/

class Solution:
    def countTrapezoids(self, points: list[list[int]]) -> int:
        res = 0
        mod = 1000000007
        points.sort(key=lambda x: x[1])
        bottom = 0
        n, i = len(points), 0
        pre = points[0][1]
        while i < n:
            top = 0
            while i < n and points[i][1] == pre:
                top += 1
                i += 1
            top_valid = int((top - 1) * top / 2) % mod
            res = (res + top_valid * bottom % mod) % mod
            bottom += top_valid
            if i < n:
                pre = points[i][1]
        return res