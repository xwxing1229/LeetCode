# https://leetcode.cn/problems/separate-squares-i/

class Solution:
    def separateSquares(self, squares: list[list[int]]) -> float:
        y_min, y_max = squares[0][1], squares[0][1]+squares[0][2]
        for x, y, l in squares:
            y_min = min(y_min, y)
            y_max = max(y_max, y+l)
        res = y_max
        eps = 1e-5
        while y_max - y_min > eps:
            mid = y_min + (y_max - y_min) / 2
            diff = 0 # above - below
            for x, y, l in squares:
                if mid <= y:
                    diff += l * l
                elif mid >= y + l:
                    diff -= l * l
                else:
                    diff += (2 * y + l - 2 * mid) * l
            if diff <= 0:
                y_max = mid
            else:
                y_min = mid
            res = mid
        return res