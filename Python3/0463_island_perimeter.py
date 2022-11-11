# https://leetcode.cn/problems/island-perimeter/

class Solution:
    def islandPerimeter(self, grid):
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: int
        """
        n_one, n_adj = 0, 0
        rows, cols = len(grid), len(grid[0])
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    n_one += 1

                    if j + 1 < cols and grid[i][j+1] == 1: # check right
                        n_adj += 1
                    if i + 1 < rows and grid[i+1][j] == 1: # check down
                        n_adj += 1

        res = 4 * n_one - 2 * n_adj
        return res
