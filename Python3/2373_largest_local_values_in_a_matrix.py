# https://leetcode.cn/problems/largest-local-values-in-a-matrix/

class Solution:
    def largestLocal(self, grid):
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: list[list[int]]
        """
        n = len(grid)
        res = [[0 for j in range(n-2)] for i in range(n-2)]
        for i in range(1, n-1):
            for j in range(1, n-1):
                tmp1 = max(grid[i-1][j-1:j+2])
                tmp2 = max(grid[i][j-1:j+2])
                tmp3 = max(grid[i+1][j-1:j+2])
                res[i-1][j-1] = max(tmp1, tmp2, tmp3)
        return res