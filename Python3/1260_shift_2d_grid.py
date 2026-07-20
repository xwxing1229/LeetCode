# https://leetcode.cn/problems/shift-2d-grid/

class Solution:
    def shiftGrid(self, grid: list[list[int]], k: int) -> list[list[int]]:
        m, n = len(grid), len(grid[0])
        res = [[0 for _ in range(n)] for _ in range(m)]
        for j in range(n):
            moves, col = (j+k) // n, (j+k) % n
            for i in range(m):
                row = (i+moves) % m
                res[row][col] = grid[i][j]
        return res