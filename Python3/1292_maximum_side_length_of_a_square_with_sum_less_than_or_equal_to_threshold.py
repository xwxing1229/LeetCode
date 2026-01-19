# https://leetcode.cn/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/

class Solution:
    def maxSideLength(self, mat: list[list[int]], threshold: int) -> int:
        m, n = len(mat), len(mat[0])
        cumsum = [[0 for _ in range(n+1)] for _ in range(m+1)]
        for i in range(m):
            for j in range(n):
                cumsum[i+1][j+1] = cumsum[i][j+1] - cumsum[i][j] + cumsum[i+1][j] + mat[i][j]
        
        res = 0
        for i in range(m):
            for j in range(n):
                side_min = res + 1
                side_max = min(m-i, n-j)
                for side in range(side_min, side_max+1):
                    curr = cumsum[i+side][j+side] - cumsum[i+side][j] - cumsum[i][j+side] + cumsum[i][j]
                    if curr > threshold:
                        break
                    elif res < side:
                        res = side
        return res