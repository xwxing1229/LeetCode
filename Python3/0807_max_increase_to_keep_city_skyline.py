# https://leetcode.cn/problems/max-increase-to-keep-city-skyline/

class Solution:
    def maxIncreaseKeepingSkyline(self, grid):
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: int
        """
        n = len(grid)
        row_max = [0 for _ in range(n)]
        for i, row in enumerate(grid):
            val_max = 0
            for val in row:
                val_max = max(val_max, val)
            row_max[i] = val_max
        col_max = [0 for _ in range(n)]
        for j in range(n):
            val_max = 0
            for i in range(n):
                val_max = max(val_max, grid[i][j])
            col_max[j] = val_max
        
        res = 0
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                res += min(row_max[i], col_max[j]) - val
        return res