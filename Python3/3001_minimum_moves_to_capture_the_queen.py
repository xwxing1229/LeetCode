# https://leetcode.cn/problems/minimum-moves-to-capture-the-queen/

class Solution:
    def minMovesToCaptureTheQueen(self, a: int, b: int, c: int, d: int, e: int, f: int) -> int:
        def check(x1, x2, x3):
            return ((x1 < x2 and x2 < x3) or (x1 > x2 and x2 > x3))
        
        if a == e:
            if (a == c) and check(b, d, f):
                return 2
            return 1
        if b == f:
            if (b == d) and check(a, c, e):
                return 2
            return 1
        if c - d == e - f:
            if (c - d == a - b) and check(c, a, e):
                return 2
            return 1
        if c + d == e + f:
            if (c + d == a + b) and check(c, a, e):
                return 2
            return 1
        return 2