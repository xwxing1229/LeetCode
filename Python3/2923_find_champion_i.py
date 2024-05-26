# https://leetcode.cn/problems/find-champion-i/

class Solution:
    def findChampion(self, grid):
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: int
        """
        res = -1
        n = len(grid)
        for i in range(n):
            if sum(grid[i]) == n-1:
                res = i
                break
        return res