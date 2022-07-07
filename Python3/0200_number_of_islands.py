# https://leetcode.cn/problems/number-of-islands/

class Solution:
    def numIslands(self, grid):
        """
        Inputs:
            grid: list[list[str]]
        Outputs:
            res: int
        """

        rows = len(grid)
        cols = len(grid[0])
        res = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "1":
                    res = res + 1
                    self.dfs(grid, r, c)
        return res
    
    def dfs(self, grid, row, col):
        grid[row][col] = 0

        rows = len(grid)
        cols = len(grid[0])
        for r, c in [(row+1, col), (row-1, col), (row, col+1), (row,col-1)]:
            if (r >= 0) and (r < rows) and (c >= 0) and (c < cols) and (grid[r][c] == "1"):
                self.dfs(grid, r, c)