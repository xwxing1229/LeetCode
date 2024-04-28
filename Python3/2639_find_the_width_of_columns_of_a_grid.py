# https://leetcode.cn/problems/find-the-width-of-columns-of-a-grid/

class Solution:
    def findColumnWidth(self, grid):
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: list[int]
        """
        m, n = len(grid), len(grid[0])
        res = [0 for _ in range(n)]
        for i in range(n):
            res[i] = len(str(grid[0][i]))
            for j in range(1, m):
                res[i] = max(res[i], len(str(grid[j][i])))
        return res