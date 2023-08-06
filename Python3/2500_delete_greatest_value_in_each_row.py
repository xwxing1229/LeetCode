# https://leetcode.cn/problems/delete-greatest-value-in-each-row/

class Solution:
    def deleteGreatestValue(self, grid):
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: int
        """
        for i in range(len(grid)):
            grid[i] = sorted(grid[i])
        res = 0
        for j in range(len(grid[0])):
            tmp = grid[0][j]
            for i in range(len(grid)):
                tmp = max(tmp, grid[i][j])
            res += tmp
        return res