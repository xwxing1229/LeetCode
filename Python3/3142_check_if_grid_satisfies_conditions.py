# https://leetcode.cn/problems/check-if-grid-satisfies-conditions/

class Solution:
    def satisfiesConditions(self, grid):
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: bool
        """
        rows, cols = len(grid), len(grid[0])
        for i in range(rows-1):
            for j in range(cols-1):
                if grid[i][j] != grid[i+1][j]:
                    return False
                if grid[i][j] == grid[i][j+1]:
                    return False
        for i in range(rows-1):
            if grid[i][-1] != grid[i+1][-1]:
                return False
        for j in range(cols-1):
            if grid[-1][j] == grid[-1][j+1]:
                return False
        return True