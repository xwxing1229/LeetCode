# https://leetcode.cn/problems/flip-square-submatrix-vertically/

class Solution:
    def reverseSubmatrix(self, grid: list[list[int]], x: int, y: int, k: int) -> list[list[int]]:
        m, n = len(grid), len(grid[0])
        res = [[grid[i][j] for j in range(n)] for i in range(m)]
        s = x + x + k - 1
        for i in range(x, x+k//2):
            for j in range(y, y+k):
                res[i][j] = grid[s-i][j]
                res[s-i][j] = grid[i][j]
        return res