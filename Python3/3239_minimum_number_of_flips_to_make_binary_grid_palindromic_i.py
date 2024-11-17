# https://leetcode.cn/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i/

class Solution:
    def minFlips(self, grid):
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: int
        """
        m, n = len(grid), len(grid[0])
        res_row = 0
        for i in range(m):
            left, right = 0, n-1
            while left < right:
                if grid[i][left] != grid[i][right]:
                    res_row += 1
                left += 1
                right -= 1
        res_col = 0
        for j in range(n):
            up, down = 0, m-1
            while up < down:
                if grid[up][j] != grid[down][j]:
                    res_col += 1
                up += 1
                down -= 1
        return min(res_row, res_col)